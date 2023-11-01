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
 * @brief Construct a new Detector object
 *
 */
Detector::Detector() {
}
/**
 * @brief Destroy the Detector object
 *
 */
Detector::~Detector() {
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
 * @brief Get a vector of class names from the neural network model.
 *
 * @param net The neural network model.
 * @return vector<String> A vector of class names.
 */
std::vector<String> Detector::ClassNames(const Net& net) {
    std::vector<std::string> names;
    std::vector<int> outLayers = network.getUnconnectedOutLayers();
    std::vector<std::string> layersNames = network.getLayerNames();
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
