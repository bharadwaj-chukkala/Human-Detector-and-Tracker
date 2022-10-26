
# include "Transformation.hpp"

Transformation::Transformation(){
    K = Eigen::MatrixXf(3,3);
    K<< 950,0,650,0,950,490,0,0,1>>;

    RT= Eigen::MatrixXf(4,4);

    RT<0,0,1,5,-1,0,0,5,0,-1,0,5,0,0,0,1>>

    P=K*RT;
   
}

Transformation::doTransform(cv::Point imageCord){
    Eigen::MatrixXf PT=P.transpose()

    Eigen::MatrixXf PSeudo=PT*(P*PT).inverse()

    // construct imagecoordinates in Homogeneous coord system

    Eigen::MatrixXf xdash=(3,1); 

    xdash<<imageCord.x,imageCors.y,1>>;

    Eigen::MatrixXf X=PSeudo*xdash;

    cv::Point3d XRobot;

    if(X(3,0)==0){
        return XRobot(0,0,0);
    }
    
    XRobot.x=X(0,0)/X(3,0);
    XRobot.y=X(1,0)/X(3,0);
    XRobot.z=X(2,0)/X(3,0);
   
    return XRobot;
   
}