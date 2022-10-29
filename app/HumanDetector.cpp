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
 * @brief Header file for HumanDetector.cpp
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iomanip>
#include<iostream>
#include<cmath>
#include "HumanDetector.hpp"
#include "ReadData.hpp"
#include "Transformation.hpp"


HumanDetector::HumanDetector() {}
HumanDetector::~HumanDetector() {}


std::vector<cv::Point> HumanDetector::calculateCenters(const std::vector<cv::Rect> &boundingBoxes){
    std::vector<cv::Point> centers;

    for (const cv::Rect &boundingBox: boundingBoxes){
        cv::Point center;
        center.x=(boundingBox.tl().x+boundingBox.br().x)/2;
        center.y=(boundingBox.tl().y+boundingBox.br().y)/2;
        centers.push_back(center);
    }

    return centers;
}


std::vector<cv::Point3d> HumanDetector::calculateRobotCordSysPoints(const std::vector<cv::Point> &centers){

    std::vector<cv::Point3d> robotCordSysPoints;
    Transformation  myTransform;
    for (const cv::Point &center: centers){

        cv::Point3d robotCordSysPoint=myTransform.doTransform(center);

        std::cout<< "Human found at Location:"<< robotCordSysPoint<<std::endl;

        robotCordSysPoints.push_back(robotCordSysPoint);
    }

    return robotCordSysPoints;

}

void HumanDetector::drawBoundingBox(cv::Mat returnedFrame,
    const std::vector<cv::Rect> &boundingBoxes,const std::vector<double> &Confidences){
        int i=0;
        for(const cv::Rect &box:boundingBoxes){

            if (Confidences[i]>=0.8){

                cv::rectangle(returnedFrame,box.tl(),box.br(),cv::Scalar(0,0,255),2);

                std::string displayID= "ID:"+ std::to_string(i+1);

                std::string confidence=cv::format("%0.2f",Confidences[i]);

                int height=box.height;
                
                std::string displayConfidences="C: "+ confidence;
            
                cv::putText(returnedFrame,displayID,cv::Point(box.tl().x,box.tl().y-10),
                cv::FONT_HERSHEY_DUPLEX,0.5,cv::Scalar(0,255,255));

                
                cv::putText(returnedFrame,displayConfidences,cv::Point(box.tl().x,box.tl().y+height-5),
                cv::FONT_HERSHEY_DUPLEX,0.5,cv::Scalar(0,255,255));
                i++;
            }
    
        }

        cv::imshow("window",returnedFrame);
        cv::waitKey(2);
        
}


void HumanDetector::detectHumans(cv::Mat returnedFrame){

    RectsandConfidences classifierOutput = humanClassifier.predict(returnedFrame);

    std::vector<cv::Rect> boundingBoxes = classifierOutput.getRectangles();
    std::vector<double> Confidences=classifierOutput.getConfidences();


    std::vector<cv::Point> centers=calculateCenters(boundingBoxes);

    std::vector<cv::Point3d> robotcordSysPoints=calculateRobotCordSysPoints(centers);

    drawBoundingBox(returnedFrame,boundingBoxes,Confidences);
    
}


