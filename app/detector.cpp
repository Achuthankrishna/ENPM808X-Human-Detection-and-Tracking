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
#include "HumanDetector.hpp"

#include <fstream>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <sstream>

/**
 * @brief Construct a new Detector object
 *
 */
Detector::Detector(){
}
/**
 * @brief Destroy the Detector object
 *
 */
Detector::~Detector(){

}

/**
 * @brief Preprocess the input frame for object detection.
 *
 * @param frame Input frame.
 * @param output Output vector for results.
 */
void Detector::processing(Mat& frame, const vector<Mat> & output){

}

/**
 * @brief Load the YoloV5 Pretrained model on COCO.
 *
 * @param model_Cfg Path to the model configuration file.
 * @param model_Wts Path to the model weights file.
 */
void Detector::load_model(std::string model_Cfg, std::string model_Wts);

/**
 * @brief Get a vector of class names from the neural network model.
 *
 * @param net The neural network model.
 * @return vector<String> A vector of class names.
 */
vector<String> Detector::ClassNames(const Net& net){

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
void Detector::drawboxes(int classID, float con, int left, int right, int bottom, Mat& frame){

}



