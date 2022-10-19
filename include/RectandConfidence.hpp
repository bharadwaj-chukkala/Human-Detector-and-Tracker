/**
 * @file RectandConfidence.hpp
 * @author Bharadwaj Chukkala (bchukkal@umd.edu),Venkata Sairam Polina (sairamp@umd.edu),Shelvin Pauly (spauly@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */



/**
 * @brief This class acts as a user defined datatype to store SVM detector output
 * 
 */
class RectandConfidence{

    std::pair p1;
    std::pair p2;
    double score;


    /**
     * @brief Construct a new Rectand Confidence object
     * 
     */
    RectandConfidence(p1_,p2_,score_):p1(_p1),p2(p2_),score(score_) {

    } 

    /**
     * @brief Destroy the Rectand Confidence object
     * 
     */
    ~RectandConfidence(){

    }

};