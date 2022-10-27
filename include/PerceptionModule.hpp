#ifndef INCLUDE_PERCEPTIONMODULE_HPP_
#define INCLUDE_PERCEPTIONMODULE_HPP_
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
 * @brief Header file for PerceptionModule.cpp
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

# include <iostream>
#include <string>
# include <opencv2/opencv.hpp>
#include <ReadData.hpp>
#include <HumanDetector.hpp>
#include <HumanClassifier.hpp>


/**
 * @brief 
 * This class initiates the entire module which consists of
 * the data reader, detector, tracker and then frame transformation
 * 
 */
class PerceptionModule {
    std::string path;
    int fileOption;
    
    public:
    ReadData frame;
    HumanDetector acmeDetector;
    /**
     * @brief Construct a new Perception Module object which asks the
     * user for input type and input path
     * 
     */
    PerceptionModule(std::string &,int &);
    /**
     * @brief Destroy the Perception Module object
     * 
     */
    ~PerceptionModule() {}
    /**
     * @brief This will run the entire module till the final frame
     * and call the required child classes and their methods with 
     * the required features depending upon the type of input.
     * Essentially it will create an object of class HumanDEtector
     * and run the detection pipeline.
     * 
     */
    void detector();
};
#endif  // INCLUDE_PERCEPTIONMODULE_HPP_
