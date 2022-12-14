#ifndef INCLUDE_HUMANCLASSIFIER_HPP_
#define INCLUDE_HUMANCLASSIFIER_HPP_
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
 * @file HumanClassifier.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu)
 * @author Venkata Sairam Polina (sairamp@umd.edu)
 * @author Shelvin Pauly (spauly@umd.edu)
 * @brief Header file for HumanClassifier.cpp
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <opencv2/opencv.hpp>
#include "../include/RectsandConfidences.hpp"

/**
 * @brief class HumanClassifier
 * This class gets a pre-trained SVM model to detect humans and 
 * classifies the sent frame, while returing the bounding
 * box and scores for that speciffic classificaation
 */
class HumanClassifier {
 public:
    cv::HOGDescriptor classifier;

    /**
     * @brief This constructor initializes the model with a trained people detector( SVM Human classifier)
     * 
     */
    HumanClassifier();

    /**
     * @brief Destroy the Human Classifier object
     * 
     */
    ~HumanClassifier();

    /**
     * @brief This method predicts the person in the frame,.e., it will detect humans in the frame.
     * 
     * @return rectandconfidence is cv::rect2d and scores for the prediction
     */

    RectsandConfidences predict(cv::Mat frame);
};
#endif  // INCLUDE_HUMANCLASSIFIER_HPP_

