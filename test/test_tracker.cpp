/**
 * @file tracker_test.cpp
 * @brief Unit tests for the Tracker class.
 */
#include <gtest/gtest.h>
#include "../include/tracker.hpp"
#include "../include/detector.hpp"
/**
 * @brief Test case for getting predictions from the Tracker.
 */
TEST(TrackerTest, TestGetPredictions) {
    // Create a black image
    cv::Mat testImage = cv::Mat::zeros(cv::Size(500, 500), CV_8UC3);

    // Draw a white rectangle (our "human") on the image
    cv::rectangle(testImage, cv::Point(50, 50),
    cv::Point(100, 100), cv::Scalar(255, 255, 255), -1);

    // Create a bounding box around the "human"
    Detector::bbox box = {0, 1.0, cv::Rect(50, 50, 50, 50)};
    std::vector<Detector::bbox> boxes = {box};

    // Now we can test the getPredictions method
    Tracker tracker;
    tracker.getPredictions(testImage, boxes);

    // Check that a tracker was created
    ASSERT_NE(tracker.trackers, nullptr);
}

/**
 * @brief Test case for getting coordinates from the Tracker.
 */
TEST(TrackerTest, TestGetCoordinates) {
    Tracker tracker;
    std::vector<float> coordinates = tracker.getCoordinates();

    // Check that the returned vector has size 3
    ASSERT_EQ(coordinates.size(), 3);
}

/**
 * @brief Test case for tracking humans using the Tracker.
 */
TEST(TrackerTest, TestHumanTrack) {
    Tracker tracker;
    cv::Mat frame;
    // frame=cv::imread("/home/ksp/Desktop/ENPM808X/ENPM808X-Human-Detection-and-Tracking/test/test_detect.jpg")

    std::vector<cv::Rect_<double>> regions = {{0, 0, 100, 100}};

    std::vector<Detector::bbox> trackedBoxes =
    tracker.humanTrack(frame, regions);
    ASSERT_EQ(trackedBoxes.size(), 0);
}
