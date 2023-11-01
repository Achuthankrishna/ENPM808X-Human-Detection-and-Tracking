/**
 * @file detector.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Implementation of the Detector class for object detection.
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include " ../include/detector.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/**
 * @brief Load the YoloV5 Pretrained model on COCO.
 *
 * @param model_Cfg Path to the model configuration file.
 * @param model_Wts Path to the model weights file.
 */
void Detector::load_model(std::string model_Cfg, std::string model_Wts) {
    void Detector::load_model(std::string model_Cfg, std::string model_Wts, std::string c_path) {
    model_Cfg="/home/achuthankrish/Desktop/ENPM/Midterm/ENPM808X-Human-Detection-and-Tracking/cfg/yolov3.cfg";
    model_Wts="./cfg/yolov3.weights";

    network=cv::dnn::readNetFromDarknet(model_Cfg,model_Wts);
    
    if (network.empty()) {
    std::cerr << "Failed to load the neural network model." << std::endl;
    return;
    }
    std::cout<<model_Wts;
    network.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    network.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

    //loading class paths
    std::ifstream ifs(c_path.c_str());
    std::string line;
    while (std::getline(ifs, line)) classes.push_back(line);
}
}

/**
 * @brief Detector method to open camera and dectect
 * 
 * @param cv_frame 
 * @return std::pair<cv::Mat, std::vector<Detector::bbox>> 
 */

std::pair<cv::Mat, std::vector<Detector::bbox>> Detector::detector(const cv::Mat& cv_frame) {
    std::vector<Detector::bbox> allBoundingBoxes;
    cv::Mat frame;

    if (!cv_frame.empty()) {
        frame = cv_frame.clone();  // Use the provided frame if not empty

        cv::Mat blob;
        cv::dnn::blobFromImage(frame, blob, 1. / 255, cv::Size(Width, Height), cv::Scalar(), true, false);
        network.setInput(blob);
        std::vector<cv::Mat> output;
        network.forward(output, network.getUnconnectedOutLayersNames());

        std::vector<Detector::bbox> bbox = processing(frame, output);

        allBoundingBoxes.insert(allBoundingBoxes.end(), bbox.begin(), bbox.end());
    }
    else {
        std::cout << "Opening Frame";
        cv::VideoCapture cap;
        cv::namedWindow("Camera Output", cv::WINDOW_NORMAL);
        cap.open(0);

        if (!cap.open(0)) { // Open the default camera (change the index if needed)
            std::cout << "Error opening camera" << std::endl;
            return std::make_pair(cv::Mat(), std::vector<Detector::bbox>());
        }
        else {
            while (cap.isOpened()) {
                cap.read(frame); // Capture a frame from the camera

                if (frame.empty()) {
                    std::cout << "Frame is empty. Exiting." << std::endl;
                    break;
                }

                cv::Mat blob;
                cv::dnn::blobFromImage(frame, blob, 1. / 255, cv::Size(Width, Height), cv::Scalar(), true, false);
                network.setInput(blob);
                std::vector<cv::Mat> output;

                try {
                    network.forward(output, network.getUnconnectedOutLayersNames());
                } catch (const cv::Exception& e) {
                    std::cerr << "Error during network forward pass: " << e.what() << std::endl;
                    break;
                }

                std::vector<Detector::bbox> bbox = processing(frame, output);


                allBoundingBoxes.insert(allBoundingBoxes.end(), bbox.begin(), bbox.end());

                // Tracker tracker;

                // // // // Call the humanTrack function using the "tracker" instance

                // tracker.getPredictions(frame,bbox);
                // tracker.humanTrack(frame);
                // tracker.boundingBox(frame,bbox);

                // std::vector<Detector::bbox> box = Tracker::humanTrack(frame);

                // Rest of your processing code

                cv::imshow("Camera Output", frame);

                char key = cv::waitKey(10);
                if (key == 'q') {
                    break; // Press 'q' to exit the loop
                }
            }

            cap.release(); // Release the camera
        }
    }

    return std::make_pair(frame, allBoundingBoxes);
}
/**
 * @brief Preprocess the input frame for object detection.
 *
 * @param frame Input frame.
 * @param output Output vector for results.
 */
std::vector<std::tuple<int, float, cv::Rect>> Detector::processing(cv::Mat& frame, const std::vector<cv::Mat> & output) {
    std::vector<int> detectedClassIds;
    std::vector<float> detectedConfidences;
    std::vector<cv::Rect> detectedBoxes;
    std::vector<bbox> bboxes;

    for (size_t i = 0; i < output.size(); ++i) {
        float* data = (float*)(output[i].data);
        for (int j = 0; j < output[i].rows; ++j, data += output[i].cols) {
            cv::Mat scores = output[i].row(j).colRange(5, output[i].cols);
            cv::Point labelPoint;
            double confidencescore;
            cv::minMaxLoc(scores, 0, &confidence, 0, &labelPoint);

            if (confidencescore > confidenceThreshold) {
                int centerX = static_cast<int>(data[0] * frame.cols);
                int centerY = static_cast<int>(data[1] * frame.rows);
                int width = static_cast<int>(data[2] * frame.cols);
                int height = static_cast<int>(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                detectedClassIds.push_back(labelPoint.x);
                detectedConfidences.push_back(static_cast<float>(confidencescore));
                detectedBoxes.push_back(cv::Rect(left, top, width, height));
            }
        }
    }

  std::vector<int> indices;
  cv::dnn::NMSBoxes(detectedBoxes, detectedConfidences, confidenceThreshold, nmsThreshold,
                    indices);
  unsigned int personid = 1;
  for (auto idx : indices) {
    cv::Rect box = detectedBoxes[idx];
    float dist = calculate_distance(box.height, frame.rows);
    drawboxes(detectedClassIds[idx], detectedConfidences[idx], box.x, box.x + box.width,
            box.y + box.height, frame, classes, personid, dist,box.y);
    // transform.camera_robot_array(z_axis, box, frame);
    std::cout << "Distance from camera  for person " << personid
      << " is: " << dist << "m" << std::endl;
    personid++;
    bbox current_bbox;
    current_bbox = std::make_tuple(detectedClassIds[idx], detectedConfidences[idx], box);
    bboxes.push_back(current_bbox);
  }
  return bboxes;
}
/**
 * @brief Calculating distance from camera to bbox
 * 
 * @param box_h 
 * @param frame_h 
 * @return float 
 */
float Detector::calculate_distance(int box_h, int frame_h) {
  int focal_l = 16;
  int sensor_h = 25;
  int averageHeight=180;
  // Conversion from pixels to milli-meter
  double height_mm = (sensor_h * box_h) / frame_h;
  // Calcuation to find distance of human from camera
  // D = (H * F) / P
  double z = (averageHeight * focal_l) / height_mm;
  return (z / 100);
}
/**
 * @brief Get a vector of class names from the neural network model.
 *
 * @param net The neural network model.
 * @return vector<String> A vector of class names.
 */
std::vector<std::string> Detector::ClassNames(const cv::dnn::Net& network) {
    std::vector<std::string> names;

    // Get the indices of the output layers, i.e., the layers with unconnected outputs
    std::vector<int> outLayers = network.getUnconnectedOutLayers();

    // Get the names of all the layers in the network
    std::vector<std::string> layersNames = network.getLayerNames();

    // Get the names of the output layers in 'names'
    names.resize(outLayers.size());
    for (size_t i = 0; i < outLayers.size(); ++i)
        names[i] = layersNames[outLayers[i] - 1];

    return names;
}

/**
 * @brief Draw bounding boxes on the input frame using class information.
 *
 * @param classID Class identifier for the detected object.
 * @param con Confidence score for detection.
 * @param left Left boundary of the bounding box.
 * @param right Right boundary of the bounding box.
 * @param bottom Bottom boundary of the bounding box.
 * @param frame Input frame to draw the bounding box on.
 */
void Detector::drawboxes(int classID, float con, int left, int right,
                        int bottom, cv::Mat& frame,const std::vector<std::string> &classes,
                        int pid, float z,int top) {
    if (classID != 0) {
        return; // Skip non-human detections
    }
    // Check if this pid already has a color assigned
    cv::Scalar color;
    auto colorIt = colorMap.find(pid);
    if (colorIt != colorMap.end()) {
        color = colorIt->second;
    } else {
        // Generate a unique color for the bounding box
        cv::RNG rng(pid); // Initialize RNG with pid for consistent color generation
        color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        colorMap[pid] = color; // Store the color for future use
    }

    // Draw a rectangle displaying the bounding box
    rectangle(frame, cv::Point(left, top), cv::Point(right, bottom), color, 3);


    // Get the label for the class name and its confidence
    std::string label = cv::format("%.2f", con);
    if (!classes.empty()) {
        CV_Assert(classID < static_cast<int>(classes.size()));
        label = "Distance: " + std::to_string(z) + " ID:" + std::to_string(pid);
    }

    // Display the label at the top of the bounding box
    int baseLine;
    cv::Size labelSize = getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    int textBottom = std::max(bottom, labelSize.height);
    rectangle(frame, cv::Point(left, bottom - round(1.5 * labelSize.height)),
              cv::Point(left + round(1.5 * labelSize.width), textBottom + baseLine),
              cv::Scalar(255, 255, 255), cv::FILLED);
    putText(frame, label, cv::Point(left, textBottom), cv::FONT_HERSHEY_SIMPLEX, 0.75,
            cv::Scalar(0, 0, 0), 1);
}
