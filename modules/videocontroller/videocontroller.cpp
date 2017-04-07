#ifndef __USED_OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // USED_OPENCV

#ifndef __VIDEO_CONTROLLER__
#include "videocontroller.h"
#endif //

VideoController::VideoController(const string winid):_winid(winid){

}

VideoController::~VideoController(){

}

void VideoController::RegisterWindow()const {
    cv::namedWindow(this->_winid, WINDOW_AUTOSIZE);
}

void VideoController::SetCurFrame(const cv::Mat frame){
    this->_curframe = frame;
}

void VideoController::ShowWindow(){
    cv::imshow(this->_winid, this->_curframe);
    cv::waitKey(5);
}
