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

#include "../include/camera.hpp"

Camera::Camera(){
    get_video = cv::VideoCapture(0);
}

Camera::~Camera(){
    get_video.release();
}

cv::Mat Camera::ReadFrame(){
    get_video.read(get_frame);
    return get_frame;
}