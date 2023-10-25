#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>


using namespace std;

/**
 * @brief Tracker classs
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
     * @brief set the tracker with the bBox frame
     *
     * @param cv_frame input frame
     * @param get_boxes get bounding box
     */
    std::vector<cv::Rect> boundingBox(cv::Mat& cv_frame, std::vector<int> get_boxes);


    /**
     * @brief track the human with bounding box
     *
     * @param cv_frame Input image frame
     */
    std::vector<cv::Rect> humanTrack(cv::Mat& cv_frame);


    /**
     * @brief Draw bounding box for the tracked target
     *
     * @param cv_frame Input image frame
     * @param get_boxes Detected bounding box from cv frame
     */
    void getPredictions(cv::Mat& cv_frame, std::vector<int> get_boxes);
};