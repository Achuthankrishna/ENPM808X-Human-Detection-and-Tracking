/**
 * @file detector_test.cpp
 * @brief Unit tests for the Detector class.
 */
#include <gtest/gtest.h>
#include "../include/detector.hpp"
/**
 * @brief Test case for loading the model.
 */
TEST(DetectorTest, LoadModelTest) {
    Detector detector;
    detector.load_model("../../cfg/yolov3.cfg",
    "../../cfg/yolov3.weights",
    "../../cfg/coco.names");

    // Check if the model is loaded successfully
    ASSERT_FALSE(detector.network.empty());
}

/**
 * @brief Test case for calculating distance.
 */
TEST(DetectorTest, CalculateDistanceTest) {
    Detector detector;
    float distance = detector.calculate_distance(120, 480);

    ASSERT_NEAR(distance, 5.0, 0.5);
}

/**
 * @brief Test case for processing a frame.
 */
TEST(DetectorTest, ProcessingTest) {
    Detector detector;
    cv::Mat frame(480, 640,
    CV_8UC3, cv::Scalar(0, 0, 0));

    std::vector<cv::Mat> output;

    std::vector<std::tuple<int, float, cv::Rect>>
    bboxes = detector.processing(frame, output);

    ASSERT_TRUE(bboxes.empty());
}

/**
 * @brief Test case for image processing using the Detector class.
 */
TEST(DetectorTest, ImageProcessing) {
    Detector detector;

    // Load your model, etc.
    detector.load_model("../../cfg/yolov3.cfg",
    "../../cfg/yolov3.weights",
    "../../cfg/coco.names");

    cv::Mat inputImage = cv::imread("test_detect.jpg");
    std::pair<cv::Mat, std::vector<Detector::bbox>>
    result = detector.detector(inputImage);

    cv::Mat outputImage = result.first;

    cv::imwrite("test_detect_result.jpg", outputImage);
    std::vector<Detector::bbox> boundingBoxes = result.second;

    // Perform assertions based on your requirements
    ASSERT_FALSE(inputImage.empty());
    ASSERT_FALSE(boundingBoxes.empty());
}
