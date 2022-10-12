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

/**
 * @brief class HumanDetector
 * This class uses a pre-trained SVM model to detect humans and 
 * returns co-ordinates of bounding box surrounding detected human
 */
 class HumanDetector{
    public:
    
    /**
     * @brief Construct a new Human Detector object
     * 
     */
    HumanDetector();

    /**
     * @brief An object to store SVM claasification model
     * 
     */

    cv::Ptr<cv::ml::SVM> svm=cv::ml::SVM::create();
    
    /**
     * @brief Object of hogdescriptor
     * 
     */
    cv::HOGDescriptor hog;
    
    /**
     * @brief Sets the Default S V M model 
     * 
     */
    void setDefaultSVM();
    /**
     * @brief Sets the Custom S V M object
     * 
     * @param SVMFilename std::string
       @return None
     */

    void setCustomSVM(std::string SVMFilename);
    /**
     * @brief ckecks the existance of the file
     * 
     * @param filename std::string
     * @return true if file exists
     * @return false if file does not exist
     */
    bool checkFileExistance(std::string &filename);
    
   /**
    * @brief Destroys the Human Detector object
    * 
    */
    ~HumanDetector();

 }

