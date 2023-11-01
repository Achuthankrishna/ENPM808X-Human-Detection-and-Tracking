/**
 * @file opencv_test.cpp
 * @brief Unit tests for OpenCV functionality.
 */

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

/**
 * @brief Test case for loading an image using OpenCV.
 */
TEST(OpenCVTest, LoadImage) {
    // Load an image from file
    std::string imagePath = __FILE__;
    imagePath = imagePath.substr(0, imagePath.find_last_of("/\\") + 1)
                              + "../app/test.jpg";
    cv::Mat image = cv::imread(imagePath);

    // Check if the image was loaded successfully
    EXPECT_FALSE(image.empty());
}
