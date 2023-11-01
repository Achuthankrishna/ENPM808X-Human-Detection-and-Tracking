/**
 * @file robot.hpp
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

#include "../include/robot.hpp"
#include "../include/camera.hpp"
#include "../include/detector.hpp"
#include "../include/tracker.hpp"
void Robot::humanDetection() {
    // float data[16] = {0, 0, -1, 0, 1, 0, 0, 0.5, 0, -1, 0, 0.5, 0, 0, 0, 1};
    cv::Mat emptyFrame;
    cv::VideoWriter videoWriter("./human1.mp4",
    cv::VideoWriter::fourcc('a', 'v', 'c', '1'),
    8, cv::Size(640, 480), true);
    Detector detector;
    detector.load_model(detector.model_Cfg,
                        detector.model_Wts, detector.c_path);
    std::pair<cv::Mat , std::vector<Detector::bbox>>
                            result = detector.detector(emptyFrame);
    cv::Mat frame = result.first;
    print(frame);
    std::vector<Detector::bbox> bbox = result.second;
    Tracker tracker;
    tracker.getPredictions(frame, bbox);
    tracker.boundingBox(frame, bbox); }
