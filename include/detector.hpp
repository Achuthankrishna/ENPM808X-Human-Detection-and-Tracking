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
 * @brief  Class for detection
 *
 */
class Detector{
    private:
        float nmsThreshold = 0.5;
        unsigned int Width;
        unsigned int height;
        float confidenceThreshold;
        std::vector<std::string> classes;
        cv::dnn::Net net;

    public:

    /**
     * @brief Constructor for Detector object
     *
     */
    Detector() {
    }

    /**
     * @brief Destroy the Detector object
     *
     */
    ~Detector() {
    }
        /**
     * @brief
     *
     */
    void processing(Mat& frame, const vector<Mat> & output);

    /**
     * @brief
     *
     */
    void drawboxes(int classID, float con, int left, int right, int bottom, Mat& frame)

    /**
     * @brief
     *
     */
    vector<Sting> ClassNames(const Net& net);

    /**
     * @brief
     *
     */
    void load_model(std::string model_Cfg, std::string model_Wts);
}
