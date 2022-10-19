/**
 * @file PeceptionModule.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu),Venkata Sairam Polina (sairamp@umd.edu),Shelvin Pauly (spauly@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

# include <iostream>
# include <opencv2/opencv.hpp>
#include <string>
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

    int number;
    std::string str;
    
    /**
     * @brief Construct a new Perception Module object which asks the
     * user for input type and input path
     * 
     */
    PerceptionModule():
    
    /**
     * @brief Destroy the Perception Module object
     * 
     */
    ~PerceptionModule():
    
    /**
     * @brief This will run the entire module till the final frame
     * and call the required child classes and their methods with 
     * the required features depending upon the type of input.
     * Essentially it will create an object of class HumanDEtector
     * and run the detection pipeline.
     * 
     */
    void detector(int, string):
}