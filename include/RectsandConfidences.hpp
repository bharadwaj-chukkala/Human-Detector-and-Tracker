#ifndef INCLUDE_RECTANDCONFIDENCE_HPP_
#define INCLUDE_RECTANDCONFIDENCE_HPP_
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
 * @brief Header file for RectandConfidence.cpp
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <utility>
# include <vector>
# include <opencv2/opencv.hpp>
/**
 * @brief This class acts as a user defined datatype to store SVM detector output
 * 
 */
class RectsandConfidences {
 public:
    std::vector<cv::Rect> rectangles;
    std::vector<double> confidences;
    /**
    * @brief Construct a new Rectand Confidence object
    * 
    */
    RectsandConfidences(const std::vector<cv::Rect> &rectangles_, const std::vector<double> &confidences_);
   
    /**
    * @brief Destroy the Rectand Confidence object
    * 
    */
    ~RectsandConfidences();
    
};
#endif  // INCLUDE_RECTANDCONFIDENCE_HPP_

