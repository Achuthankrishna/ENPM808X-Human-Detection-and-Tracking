#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>


TEST(dummy_test, this_should_pass) {
  EXPECT_EQ(1, 1);
}
/**
 * @brief Construct a new TEST object for OpenCV
 * 
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

// TEST(dummy_test, this_should_pass_too) {
//   EXPECT_EQ(my_function1(3), 3);
// }

// TEST(dummy_test, this_will_fail) {
//   EXPECT_EQ(my_function2(3.2), 3.2);
// }
