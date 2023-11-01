/**
 * @file HumanDetector.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Class for human detection.
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/**
 * @brief Class for human detection.
 */
class Detector{
    private:

    float nmsThreshold = 0.5; ///< Non-Maximum Suppression threshold for human detection.
    unsigned int Width; ///< Width of the detection model.
    unsigned int Height; ///< Height of the detection model.
    float confidenceThreshold; ///< Confidence threshold for human detection.
    std::vector<std::string> classes; ///< List of classes for human detection.
    cv::dnn::Net net; ///< The neural network model for human detection.

    public:

    /**
     * @brief Constructor for Detector object
     *
     */
    Detector() {
    }

    /**
     * @brief Destructor for the Detector object.
     */
    ~Detector() {
    }

    /**
     * @brief Load the human detection model from configuration and weights files.
     *
     * @param model_Cfg Path to the model configuration file.
     * @param model_Wts Path to the model weights file.
     */
    void load_model(std::string model_Cfg, std::string model_Wts);

    /**
     * @brief Process a frame for human detection.
     *
     * @param frame Input frame for human detection.
     * @param output Vector of Mat objects for output.
     */
    void processing(Mat& frame, const vector<Mat> & output);

    /**
     * @brief Draw bounding boxes for detected humans.
     *
     * @param classID Class identifier for the detected human.
     * @param con Confidence score for human detection.
     * @param left Left boundary of the bounding box.
     * @param right Right boundary of the bounding box.
     * @param bottom Bottom boundary of the bounding box.
     * @param frame Frame to draw the bounding box on.
     */
    void drawboxes(int classID, float con, int left, int right,
                        int bottom, cv::Mat& frame,const std::vector<std::string> &classes,
                        int pd, float z,int top)

    /**
     * @brief Get the class names for human detection from the neural network model.
     *
     * @param net The neural network model.
     * @return A vector of class names for humans.
     */
    std::vector<std::Sting> ClassNames(const Net& net);


}
