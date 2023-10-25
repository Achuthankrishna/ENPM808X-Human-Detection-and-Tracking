#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/tracking.hpp>


using namespace std;

/**
 * @brief Tracker classs
 *
 */
class Tracker {

 private:

    std::vector<int> get_boxes;


 public:

    /**
     * @brief Constructor of Tracker class
     */
    Tracker() {}
    /**
     * @brief Destructor of Tracker class
     */
    ~Tracker() {}
}