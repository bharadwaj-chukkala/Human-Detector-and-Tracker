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
 * @brief test cpp file for human classifier
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include "../include/HumanClassifier.hpp"
#include "../include/ReadData.hpp"


TEST(HumanClassifier_Test, Human_Classified) {
    HumanClassifier Model;

    ReadData input_reader;
    cv::Mat frame = input_reader.readFrame("/home/bharadwaj/ENPM808X_Midterm_project/test_data/image1.png");

    RectsandConfidences detectedOutput = Model.predict(frame);
    std::vector<cv::Rect> boundingBoxes = detectedOutput.getRectangles();
    std::vector<double> confidences = detectedOutput.getConfidences();
    EXPECT_EQ(boundingBoxes.size(), confidences.size());
}

TEST(check_prediction, testing_predict_pass) {
    //
    ReadData input_reader;
    cv::Mat frame = input_reader.readFrame("/home/bharadwaj/ENPM808X_Midterm_project/test_data/image1.png");
    //
    HumanClassifier classifier;
    
    RectsandConfidences test_Object1 = classifier.predict(frame);
    

    std::vector<cv::Rect> rectangles;
    std::vector<double> scores;

    cv::Rect rectangle1(468, 249, 124, 247);
    rectangles.push_back(rectangle1);
    cv::Rect rectangle2(308, 257, 430-308, 500-257);
    rectangles.push_back(rectangle2);
    double score = 0.739757;
    scores.push_back(score);
    score = 1.88305;
    scores.push_back(score);
    score = 1.69962;
    scores.push_back(score);
    score = 0.106604;
    scores.push_back(score);


    RectsandConfidences test_Object2(rectangles, scores);

    EXPECT_EQ(scores[0], test_Object2.getConfidences()[0]);
    EXPECT_EQ(test_Object1.getRectangles()[0].tl().x, test_Object2.getRectangles()[0].tl().x);
}
