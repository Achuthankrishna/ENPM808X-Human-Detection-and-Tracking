/**
 * @file camera.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Class for capturing frames from a camera.
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
/**
 * @brief Class representing a camera.
 */
class Camera{
    private:

    cv::VideoCapture get_video; ///< Video capture object.
    cv::Mat get_frame; ///< The captured frame.

    public:
    /**
     * @brief Constructor for Camera class
     *
     */
    explicit Camera(std::string videoPath);

    /**
     * @brief Destructor for Camera class
     *
     */
    ~Camera();

    /**
     * @brief Capture and retrieve a frame from the camera.
     *
     * @return A cv::Mat representing the captured frame.
     */
    cv::Mat ReadFrame();

};
