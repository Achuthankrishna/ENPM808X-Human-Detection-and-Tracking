/**
 * @file camera_test.cpp
 * @brief Unit tests for the Camera class.
 */

#include "../include/camera.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test case for reading a frame from a camera.
 */
TEST(CameraTest, ReadFrame) {
    // Create a temporary video file for testing (you can replace this with an actual video file)
    cv::VideoCapture test_video;
    cv::Mat test_frame;
    test_video.open(0);
    test_video >> test_frame;
    cv::imwrite("test_frame.jpg", test_frame);

    // Instantiate the Camera object
    Camera test_camera("test_frame.jpg");

    // Read a frame from the camera
    cv::Mat result_frame = test_camera.ReadFrame();

    // Compare the dimensions of the frames
    EXPECT_EQ(test_frame.rows, result_frame.rows);
    EXPECT_EQ(test_frame.cols, result_frame.cols);

    // Delete the temporary video file
    remove("test_frame.jpg");
}
