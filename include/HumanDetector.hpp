/**
 * @file HumanDetector.hpp
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
    std::pair calculateCentroid(cv::Rect2d);

    /**
     * @brief Moving from 2d Image coordinate system to 3d Robot coordinate system and display it
     * 
     * @param Point Centroid for the bounding box
     * @return 
     */
    void transform(std::pair);

    
    /**
    * @brief Destroys the Human Detector object
    * 
    */
    ~HumanDetector();

 }

