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
#include <sstream>
Detector::Detector(){
    return 0;
}
void Detector::processing(Mat& frame, const vector<Mat> & output){

}
void Detector::drawboxes(int classID, float con, int left,
        int right, int bottom, Mat& frame){

        }
vector<String> Detector::ClassNames(const Net& net){

}