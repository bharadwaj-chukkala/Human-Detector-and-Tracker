#ifndef INCLUDE_TRANSFORMATION_HPP_
#define INCLUDE_TRANSFORMATION_HPP_
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
 * @file Transformation.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu)
 * @author Venkata Sairam Polina (sairamp@umd.edu)
 * @author Shelvin Pauly (spauly@umd.edu)
 * @brief Header file for Transformation.hpp
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

/**
 * @brief Class transformation for transforming
 * from image coordinates to robot world
 * coordinates.
 * 
 */
class Transformation {
    /**
     * @brief Private data member for storing the
     * Projection Matrix
     * 
     */
    Eigen::MatrixXf P;

 public:
    /**
     * @brief Construct a new Transformation object
     * 
     */
    Transformation();

    /**
     * @brief Destroy the Transformation object
     * 
     */
    ~Transformation() {
    }
    /**
     * @brief Computes the 3d robot system coordinates,
     * using homogenous transformation
     * 
     * @param imageCoord The 2D image coordinates
     * @return cv::Point3d 3D robot system coordinates
     */
    cv::Point3d doTransform(cv::Point imageCoord);

};
#endif  // INCLUDE_TRANSFORMATION_HPP_
