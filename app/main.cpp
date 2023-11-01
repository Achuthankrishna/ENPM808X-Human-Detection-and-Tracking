/**
 * @file main.cpp
 * @author Vyshnav Achuthan (vyachu07@umd.edu)
 * @author Kiran S Patil (kpatil27@umd.edu)
 * @author Surya Chappidi (chappidi@umd.edu)
 * @brief main file
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/camera.hpp"
#include "../include/detector.hpp"
#include "../include/tracker.hpp"
#include "../include/robot.hpp"


int main() {

    float data[16] = {0, 0, -1, 0, 1, 0, 0, 0.5, 0, -1, 0, 0.5, 0, 0, 0, 1};
    cv::Mat emptyFrame;
    cv::VideoWriter videoWriter("human.avi", cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, cv::Size(640, 480), true);
    std::vector<Detector::bbox> bboxs;

    Robot robot;

}
