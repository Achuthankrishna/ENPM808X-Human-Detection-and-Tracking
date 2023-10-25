/**
 * @file tracker.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Implementation of the Tracker class for human tracking.
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include "../include/tracker.hpp"
/**
 * @brief Construct a new Tracker object
 *
 */
Tracker::Tracker() {
}
/**
 * @brief Destroy the Tracker object
 *
 */
Tracker::~Tracker() {
}
/**
 * @brief Obtain predictions from detector
 *
 * @param cv_frame
 * @param get_boxes
 */
void Tracker::getPredictions(cv::Mat& cv_frame, std::vector<int> get_boxes) {
}

/**
 * @brief Method to construct bounding box using frame obtained
 *
 * @param cv_frame
 * @param get_boxes
 * @return std::vector<cv::Rect>
 */
std::vector<cv::Rect> boundingBox(const cv::Mat& cv_frame,
                                    const std::vector<int> get_boxes) {
    return {};
}
/**
 * @brief Get the frame and track using ByteTrack
 *
 * @param cv_frame
 * @return std::vector<cv::Rect>
 */

std::vector<cv::Rect> humanTrack(const cv::Mat& cv_frame) {
    return {};
}

