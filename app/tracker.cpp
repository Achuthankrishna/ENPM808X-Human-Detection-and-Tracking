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
    trackers= cv::MultiTracker::create();
    for(Detector::bbox get_box : get_boxes)
    {
        trackers->add(cv::TrackerKCF::create(),cv_frame,cv::Rect2d(get_box));
        cv::RNG rng(0);
        colors.push_back(cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
                                rng.uniform(0, 255)));
    }
}
/**
 * @brief Get coordinates to initialise tracker wrt robot frames
 * 
 * @return std::vector<float> 
 */
std::vector<float> Tracker::getCoordinates() {
  std::vector<float> coordinates;
  coordinates.push_back(pose.at<float>(0, 3));
  coordinates.push_back(pose.at<float>(1, 3));
  coordinates.push_back(pose.at<float>(2, 3));
  return coordinates;
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
       std::vector<cv::Rect> trackedRegions;

    for (unsigned i = 0; i < get_boxes.size(); i++) {
        std::cout << "ID: " << get_boxes[i].id << " Confidence: " << get_boxes[i].confidence << std::endl;
        cv::rectangle(cv_frame, get_boxes[i].box, colors[i], 2, 1);
        std::string label = "Object " + std::to_string(i + 1);
        cv::putText(cv_frame, label, cv::Point(get_boxes[i].box.x, get_boxes[i].box.y),
                    cv::FONT_HERSHEY_SIMPLEX, 0.75, colors[i], 2);

        // Add the tracked region to the output vector
        trackedRegions.push_back(get_boxes[i].box);
    }

    return trackedRegions;
}
/**
 * @brief Get the frame and track using ByteTrack
 *
 * @param cv_frame
 * @return std::vector<cv::Rect>
 */

std::vector<cv::Rect> humanTrack(const cv::Mat& cv_frame) {
        trackers->update(frame)
    std::vector<Detector::bbox> updt;
    std::vector<cv::Rect2d> objects_list = trackers->getObjects();
  std::for_each(objects_list.begin(),objects_list.end(),[&updt](cv::Rect2d tracked_object){
    updt.push_back({0, 100.0, cv::Rect(tracked_object)});
  });
  return updt;
}

