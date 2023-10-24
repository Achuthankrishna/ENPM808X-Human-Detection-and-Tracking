/**
 * @file HumanDetector.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include<string>
#include<algorithm>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2/highgui.hpp>
/**
 * @brief  Driver Class for detection
 * 
 */
class Detector{
    private:
        float nmsThreshold = 0.5;
        unsigned int Width;
        unsigned int height;
        float confidenceThreshold;
    public:
        void processing(Mat& frame, const vector<Mat> & output);
        void drawboxes(int classID, float con, int left,
        int right, int bottom, Mat& frame)
        vector<Sting> ClassNames(const Net& net);
}

