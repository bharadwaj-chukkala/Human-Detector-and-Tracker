/**
 * @file ReadData.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu),Venkata Sairam Polina (sairamp@umd.edu),Shelvin Pauly (spauly@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief ReadData class which reads the input frame by frame 
 * 
 */
class ReadData{
    cv::Mat frame;

    public:
    /**
     * @brief Construct a new Read Data object which initializes the frame with an empty image
     * 
     */
    ReadData();

    /**
     * @brief Destroy the Read Data object
     * 
     */

    ~ReadData();
    
    /**
     * @brief method which reads an image from the path
     * 
     * @return cv::Mat image(frame)
     */
    cv::Mat readFrame(std::string path);
};
