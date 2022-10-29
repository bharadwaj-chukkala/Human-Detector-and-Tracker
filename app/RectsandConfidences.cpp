# include "RectsandConfidences.hpp"


RectsandConfidences::RectsandConfidences(const std::vector<cv::Rect> &rectangles_, const std::vector<double> &confidences_):
 rectangles(rectangles_), confidences(confidences_) {
    }

RectsandConfidences::~RectsandConfidences(){}

std::vector<cv::Rect> RectsandConfidences::getRectangles(){
        return rectangles;
    }

std::vector<double> RectsandConfidences::getConfidences(){
        return confidences;
    }
