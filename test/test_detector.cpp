#include "../include/detector.hpp"
#include <gtest/gtest.h>


TEST(DetectorTest, ImageProcessing) {
    Detector detector;

    // Load your model, etc.
    detector.load_model("model_Cfg", "model_Wts", "c_path");

    // Load an input image for processing
    cv::Mat inputImage = cv::imread("./test/test_detect.jpg"); // Replace with actual image path

    // Call the detector function with the input image
    std::pair<cv::Mat, std::vector<Detector::bbox>> result = detector.detector(inputImage);

    // Access the output
    cv::Mat outputImage = result.first;

    cv::imwrite("./test/test_detect_result.jpg", outputImage);
    std::vector<Detector::bbox> boundingBoxes = result.second;

    // Perform assertions based on your requirements
    ASSERT_FALSE(outputImage.empty());
    ASSERT_FALSE(boundingBoxes.empty());

}
