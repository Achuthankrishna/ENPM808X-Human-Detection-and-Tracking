/**
 * @file Camera.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "../include/camera.hpp"
/**
 * @brief Construct a new Camera:: Camera object
 *
 */
Camera::Camera(){
    get_video = cv::VideoCapture(0);
}
/**
 * @brief Destroy the Camera:: Camera object
 *
 */
Camera::~Camera(){
    get_video.release();
}
/**
 * @brief Method to read the camera frames obtained
 *
 * @return cv::Mat
 */
cv::Mat Camera::ReadFrame(){
    get_video.read(get_frame);
    return get_frame;
}
