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
 * @file Transformation.cpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu)
 * @author Venkata Sairam Polina (sairamp@umd.edu)
 * @author Shelvin Pauly (spauly@umd.edu)
 * @brief implementation for Transformation.hpp
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# include "Transformation.hpp"
# include <opencv2/opencv.hpp>

Transformation::Transformation() {
    Eigen::MatrixXf K;
    Eigen::MatrixXf I;
    Eigen::MatrixXf RT;
    
    K = Eigen::MatrixXf(3,3);
    K<< 950,0,650,0,950,490,0,0,1;

    I = Eigen::MatrixXf(3, 4);
    I << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0;

    RT= Eigen::MatrixXf(4,4);

    RT<<0,0,1,5,-1,0,0,5,0,-1,0,5,0,0,0,1;

    P=K*I*RT;
   
}

cv::Point3d Transformation::doTransform(cv::Point imageCord){
    Eigen::MatrixXf PT=P.transpose();

    Eigen::MatrixXf Pseudo=PT*(P*PT).inverse();

    // construct imagecoordinates in Homogeneous coord system

    Eigen::MatrixXf xdash(3,1); 

    xdash<<imageCord.x,imageCord.y,1;

    Eigen::MatrixXf X=Pseudo*xdash;

    cv::Point3d XRobot(0,0,0);

    if(X(3,0)==0){
        return XRobot;
    }
    
    XRobot.x=X(0,0)/X(3,0);
    XRobot.y=X(1,0)/X(3,0);
    XRobot.z=X(2,0)/X(3,0);
   
    return XRobot;
   
}