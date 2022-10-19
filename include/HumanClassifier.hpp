/**
 * @file HumanClassifier.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu),Venkata Sairam Polina (sairamp@umd.edu),Shelvin Pauly (spauly@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <opencv2/opencv.hpp>

typedef cv::HOGDescriptor classifier


class HumanClassifier {

    
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
    rectandconfidence detect();
}