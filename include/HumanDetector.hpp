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
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

 # include <iostream>
 # include <opencv2/opencv.hpp>
 # include <string>
 # include <"HumanClassifier.hpp">

/**
 * @brief class HumanDetector
 * This class uses a pre-trained SVM model to detect humans and 
 * returns co-ordinates of bounding box surrounding detected human
 */
 class HumanDetector:Public HumanClassifier{
    public:
    
    /**
     * @brief Construct a new Human Detector object
     * 
     */
    HumanDetector();

    /**
     * @brief This function calls predict function from the classifier. The 2d image points for the bounding box
     * is displayed.
     * @return Rect2d points of the bounding box.
     * 
     */
    cv::Rect2d drawBoundingBox();
    
    /**
     * @brief Finds the centroid of the bounding box
     * 
     * @param cv:Rect2d bounding box points
       @return Centroid point
     */
    Point calculateCentroid(cv:Rect2d);

    /**
     * @brief Moving from 2d Image coordinate system to 3d Robot coordinate system and display it
     * 
     * @param Point Centroid for the bounding box
     * @return 
     */
    void transform(Point);

    
    /**
    * @brief Destroys the Human Detector object
    * 
    */
    ~HumanDetector();

 }

