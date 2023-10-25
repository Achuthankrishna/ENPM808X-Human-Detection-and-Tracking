/**
 * @file Camera.hpp
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
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using cv;


/**
 * @brief Class for Camera.
 *
 */
class Camera{
    private:

    cv::VideoCapture get_video;
    cv::Mat get_frame;

    public:

    /**
     * @brief Constructor for Camera class
     *
     */
    Camera();

    /**
     * @brief Destructor for Camera class
     *
     */
    ~Camera();

    /**
     * @brief Get Frames
     *
     * @return cv::Mat
     */
    cv::Mat ReadFrame();

};

