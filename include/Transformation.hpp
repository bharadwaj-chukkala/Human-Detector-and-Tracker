
# include <Eigen/Dense>

class Transformaton{
    Eigen::MatrixXf K;
    Eigen::MatrixXf RT;
    Eigen::MatrixXf P;
    public:
    Transformation();

    cv::Point3D doTransform(cv::Point imageCoord){

    }

}