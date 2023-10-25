/**
 * @file detector.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief
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
 * @brief Construct a new Detector:: Detector object
 * 
 */
Detector::Detector(){
}
/**
 * @brief Destroy the Detector:: Detector object
 * 
 */
Detector::~Detector(){

}
/**
 * @brief Processing - Method to pre process the frames 
 * 
 * @param frame 
 * @param output 
 */
void Detector::processing(Mat& frame, const vector<Mat> & output){

}
/**
 * @brief Loading YoloV5 Pretained model on COCO
 * 
 * @param model_Cfg 
 * @param model_Wts 
 */

void Detector::load_model(std::string model_Cfg, std::string model_Wts);

/**
 * @brief Vector of class names - Taken from pretrained weights
 * 
 * @param net 
 * @return vector<String> 
 */
vector<String> Detector::ClassNames(const Net& net){

}
/**
 * @brief Method to draw bounding boxes using the Class ID obtained 
 * 
 * @param classID 
 * @param con 
 * @param left 
 * @param right 
 * @param bottom 
 * @param frame 
 */
void Detector::drawboxes(int classID, float con, int left, int right, int bottom, Mat& frame){

}



