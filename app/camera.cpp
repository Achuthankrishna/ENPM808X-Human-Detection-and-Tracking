/**
 * @file camera.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief camera class implementation
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/camera.hpp"

/**
 * @brief Construct a new Camera:: Camera object
 *
 */
Camera::Camera(std::string videoPath) {
    get_video.open(videoPath);
    if (!get_video.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        throw("Camera Not Captured");
    }
}


/**
 * @brief Destroy the Camera:: Camera object
 *
 */
Camera::~Camera() {
    // get_video.release();
    if (get_video.isOpened()) {
        get_video.release();
    }
}


/**
 * @brief Method to read the camera frames obtained
 *
 * @return cv::Mat
 */
cv::Mat Camera::ReadFrame() {
    cv::Mat get_frame;
    get_video >> get_frame;
    if (get_frame.empty()) throw("Not able to read frame");
    return get_frame;
}





