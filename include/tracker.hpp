/**
 * @file tracker.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Tracker class for human tracking.
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>


using namespace std;

/**
 * @brief Tracker class for human tracking.
 *
 */
class Tracker {

 private:

    std::vector<int> get_boxes;


 public:

    /**
     * @brief Constructor of Tracker class
     */
    Tracker() {}

    /**
     * @brief Destructor of Tracker class
     */
    ~Tracker() {}

    /**
     * @brief Set the tracker with the bounding box frame.
     *
     * This function sets the tracker with the provided bounding box frame.
     *
     * @param cv_frame Input frame for tracking.
     * @param get_boxes Bounding box information.
     * @return A vector of Rectangles representing the tracked regions.
     */
    std::vector<cv::Rect> boundingBox(cv::Mat& cv_frame, std::vector<int> get_boxes);


    /**
     * @brief Track the human object with bounding boxes.
     *
     * This function tracks a human object in the given input image frame using bounding boxes.
     *
     * @param cv_frame Input image frame.
     * @return A vector of Rectangles representing the tracked human object.
     */
    std::vector<cv::Rect> humanTrack(cv::Mat& cv_frame);


    /**
     * @brief Draw bounding boxes for the tracked human target.
     *
     * This function draws bounding boxes for the tracked human target on the input image frame.
     *
     * @param cv_frame Input image frame.
     * @param get_boxes Detected bounding box from the input frame.
     */
    void getPredictions(cv::Mat& cv_frame, std::vector<int> get_boxes);
};