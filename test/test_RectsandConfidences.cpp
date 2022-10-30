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
 * @brief test cpp file to create individual test cases
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include "../include/RectsandConfidences.hpp"
#include "../include/ReadData.hpp"
#include "../include/HumanClassifier.hpp"

/**
 * @brief Construct a new TEST object to test classifying model predictions
 * 
 */
TEST(Testing_type, RectsnScores_Test) {
    ReadData input_reader;
    std::string filepath = "../test_data/image1.png";
    cv::Mat frame = input_reader.readFrame(filepath);
    //
    HumanClassifier classifier;
    RectsandConfidences test_Object = classifier.predict(frame);
    int size = test_Object.getRectangles().size();
    for (int i = 1; i < size ; i++) {
        if (test_Object.getConfidences()[i] >= 1.8) {
            EXPECT_EQ(232, test_Object.getRectangles()[i].tl().x);
            EXPECT_EQ(249, test_Object.getRectangles()[i].tl().y);
            EXPECT_EQ(356, test_Object.getRectangles()[i].br().x);
            EXPECT_EQ(496, test_Object.getRectangles()[i].br().y);
        }
    }
}

