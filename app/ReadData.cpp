/**
 * @file ReadData.cpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu),Venkata Sairam Polina (sairamp@umd.edu),Shelvin Pauly (spauly@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include <"ReadData.hpp">

ReadData::ReadData(): this->frame(300, 500, CV_8UC3, Scalar(0, 0, 0)) {

}

ReadData::~ReadData(cv::Mat frame) {
    std::cout<<"Destructor of class ReadDatat";
}

cv::Mat ReadData::ReadFrame(std::string filename) {
    cv::Mat frame = cv::imread(filename);
    cv::imshow("Frame", frame);
    return frame;
}
