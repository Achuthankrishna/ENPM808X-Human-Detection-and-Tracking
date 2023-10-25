/**
 * @file robot.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @brief Robot Class
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "camera.hpp"
#include "detector.hpp"
#include "tracker.hpp"
/**
 * @brief Robot Class to intergrate individual classes
 * 
 */
class Robot{
 private:

    int human_counter = 0;

    Detector detector();
    Camera camera();
    Tracker tracker();

 public:
    /**
     * @brief Human Track Method to get tracker
     * 
     * @param cv_frame 
     * @return std::vector<cv::Rect> 
     */

    std::vector<cv::Rect> humanTrack(cv::Mat& cv_frame);
    /**
     * @brief Get Frames from Camera
     * 
     * @return cv::Mat 
     */
    cv::Mat ReadFrame();
    /**
     * @brief Get Bounding Box from Detector
     * 
     * @param bbox 
     * @return std::vector<cv::Rect> 
     */

    std::vector<cv::Rect> boundingBox(cv::Rect& bbox);
};