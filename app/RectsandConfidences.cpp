# include "RectsandConfidences.hpp"


RectsandConfidences::RectsandConfidences(const std::vector<cv::Rect> &rectangles_, const std::vector<double> &confidences_):
 rectangles(rectangles_), confidences(confidences_) {
    }

RectsandConfidences::~RectsandConfidences(){}
