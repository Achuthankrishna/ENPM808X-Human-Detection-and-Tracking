/**
 * @file detector_test.cpp
 * @brief Unit tests for the Detector class.
 */

#include "../include/detector.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test case for loading the model.
 */
TEST(DetectorTest, LoadModelTest) {
    Detector detector;
    detector.load_model("../cfg/yolov3.cfg", "../cfg/yolov3.weights", "../cfg/coco.names");
    // Check if the model is loaded successfully
    ASSERT_FALSE(detector.network.empty());
}

/**
 * @brief Test case for calculating distance.
 */
TEST(DetectorTest, CalculateDistanceTest) {
    Detector detector;
    // Assume a frame height of 480 pixels and a box height of 120 pixels
    float distance = detector.calculate_distance(120, 480);

    // Check if the calculated distance is within a reasonable range
    ASSERT_NEAR(distance, 5.0, 0.5);  // Adjust the expected value as needed
}

/**
 * @brief Test case for processing a frame.
 */
TEST(DetectorTest, ProcessingTest) {
    Detector detector;
    cv::Mat frame(480, 640, CV_8UC3, cv::Scalar(0, 0, 0)); // Create a black frame

    // Simulate the output from the neural network (no detections)
    std::vector<cv::Mat> output;
    // Ensure that 'output' contains no detection results

    std::vector<std::tuple<int, float, cv::Rect>> bboxes = detector.processing(frame, output);

    // Check if the 'bboxes' vector is empty when no objects are detected
    ASSERT_TRUE(bboxes.empty());
}

/**
 * @brief Test case for image processing using the Detector class.
 */
TEST(DetectorTest, ImageProcessing) {
    Detector detector;

    // Load your model, etc.
    detector.load_model("../cfg/yolov3.cfg", "../cfg/yolov3.weights", "../cfg/coco.names");

    // Load an input image for processing
    cv::Mat inputImage = cv::imread("test_detect.jpg");
    // Call the detector function with the input image
    std::pair<cv::Mat,std::vector<Detector::bbox>> result = detector.detector(inputImage);

    // Access the output
    cv::Mat outputImage = result.first;

    cv::imwrite("test_detect_result.jpg", outputImage);
    std::vector<Detector::bbox> boundingBoxes = result.second;

    // Perform assertions based on your requirements
    ASSERT_FALSE(inputImage.empty());
    ASSERT_FALSE(boundingBoxes.empty());
}
