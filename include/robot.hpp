/**
 * @file robot.hpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief Robot class to integrate individual classes.
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
 * @brief Robot class for performing human tracking.
 *
 * The Robot class integrates detection, camera, and tracking functionalities to track humans.
 */
class Robot{
 private:

   int human_counter = 0; ///< Counter for tracking the number of detected humans.
   Detector detector(); ///< An instance of the Detector used for human detection.
   Camera camera(); ///< An instance of the Camera used for capturing frames.
   Tracker tracker(); ///< An instance of the Tracker used for human tracking.

 public:

    /**
     * @brief Track human objects in the input frame.
     *
     * This function uses the integrated detector and tracker to track human objects in the given frame.
     *
     * @param cv_frame Input frame for human tracking.
     * @return A vector of Rectangles representing the tracked human objects.
     */
    std::vector<cv::Rect> humanTrack(cv::Mat& cv_frame);

    /**
     * @brief Read a frame from the camera.
     *
     * This function captures a frame from the camera and returns it as a cv::Mat.
     *
     * @return A cv::Mat representing the captured frame.
     */
    cv::Mat ReadFrame();

    /**
     * @brief Set the bounding box for tracking.
     *
     * This function sets the bounding box for tracking in the integrated tracker.
     *
     * @param bbox The bounding box to be tracked.
     * @return A vector of Rectangles representing the tracked region.
     */
    std::vector<cv::Rect> boundingBox(cv::Rect& bbox);
    /**
     * @brief Human detection method
     * 
     */

    void humanDetection();
};
