#include <iostream>
#include <array>
#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief ReadData class which reads the input frame by frame 
 * 
 */
class ReadData{
    //cv::Mat frame;

    public:
    /**
     * @brief Construct a new Read Data object
     * 
     */
    ReadData() {

    }

    /**
     * @brief Destroy the Read Data object
     * 
     */

    ~ReadData() {

    }
    /**
     * @brief method which reads an image from the path
     * 
     * @return cv::Mat image(frame)
     */
    cv::Mat readFrame(std::string path) {

    };
}
