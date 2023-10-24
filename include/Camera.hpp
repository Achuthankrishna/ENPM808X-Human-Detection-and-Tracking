#pragma once

#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include<string>
#include<algorithm>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2/highgui.hpp>

using cv;
/**
 * @brief Class for getting Camera
 * 
 */
class Camera{
    
    cv::videoCapture video;
    Mat frame;
    double<vector> cameraCoord;
    

 public:
    Camera() {
    //Check if camera is on
      if (!video.isOpened()) {
        std::cout << "Camera not ON" << std::endl;
      }
    }
    cv::Mat get_frames() {
      video >> frame;
      if (frame.empty()){
        break;
      }
      imshow("Frame", frame);
      return frame;
    }
    ~Camera() {
      video.release();
      cv::destroyAllWindows();
    }
}