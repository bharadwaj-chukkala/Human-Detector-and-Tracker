#ifndef INCLUDE_HUMANDETECTOR_HPP_
#define INCLUDE_HUMANDETECTOR_HPP_
/**
 * MIT License

 * Copyright (c) [2022] [Bharadwaj Chukkala, Venkata Sairam Polina, and Shelvin Pauly]

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *  
 * @file HumanDetector.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu)
 * @author Venkata Sairam Polina (sairamp@umd.edu)
 * @author Shelvin Pauly (spauly@umd.edu)
 * @brief Header file for HumanDetector.cpp
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

# include <iostream>
# include <string>
#include <algorithm>
# include <utility>
# include <vector>
# include <opencv2/opencv.hpp>
# include <../include/HumanClassifier.hpp>
# include <../include/RectsandConfidences.hpp>

/**
 * @brief class HumanDetector
 * This class uses a pre-trained SVM model to detect humans and 
 * uses co-ordinates of bounding box surrounding detected human
 * to find humans in robot Cordinate system.
 */
class HumanDetector{
  HumanClassifier humanClassifier;



    /**
     * @brief Finds the centers of all boundingBoxes in an image
     * 
     * @param boundingBoxes 
     * @return std::vector<cv::Point>& Center Points.
     */
    std::vector<cv::Point> calculateCenters(
      const std::vector<cv::Rect> &boundingBoxes);


    /**
     * @brief Moving from 2d Image coordinate system to 3d Robot coordinate system and displaying 
     * detected humans position in robot Coordinate System.
     * 
     * @param centers returned from calculateCenters method.
     * @return std::vector<cv::Point3d> Locations where humans are detected in 
     * robot Coordinate system.
     */
    std::vector<cv::Point3d> calculateRobotCordSysPoints(
      const std::vector<cv::Point> &centers,
    std::vector<double> &confidences);

    /**
     * @brief This function draws bounding boxes around detected humans.
     * 
     * @param returnedFrame image
     * @param boundingBoxes  Vector of rectangle Coordinates returned by HumanClassifier.
     * @param Confidences Prediction Confidence scores returned by HumanClassifier
     */
    int drawBoundingBox(cv::Mat returnedFrame,
      const std::vector<cv::Rect> &boundingBoxes,
      const std::vector<double> &Confidences);

 public:
    /**
     * @brief Construct a new Human Detector object
     * 
     */
    HumanDetector();

    /**
    * @brief Destroys the Human Detector object
    * 
    */
    ~HumanDetector();



    /**
     * @brief This method carries out the detection pipeline.
     * It calls Humanclassifier to detect humans, which returns 
     * RectsandConfidences.
     * 
     * RectsandConfidences is split in to boundingBoxes and confidences.
     * 
     * 
     * centers are calculated from boundingBoxes which are further transformed
     * to robotCoordinate system.
     * 
     * @param returnedFrame original Image
     * @return None
     */
    int detectHumans(cv::Mat returnedFrame);
};
#endif  // INCLUDE_HUMANDETECTOR_HPP_

