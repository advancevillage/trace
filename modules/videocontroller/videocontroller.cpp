#ifndef USED_OPENCV
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // USED_OPENCV

#ifndef VIDEO_CONTROLLER
#include "videocontroller.h"
#endif //

VideoController::VideoController(const string w_id):win_id(w_id){

}

VideoController::~VideoController(){

}

void VideoController::RegisterWindow()const {
    cv::namedWindow(this->win_id, WINDOW_AUTOSIZE);
}

void VideoController::SetCurFrame(const cv::Mat frame){
    this->cur_frame = frame;
}

void VideoController::ShowWindow(){
    cv::imshow(this->win_id, this->cur_frame);
    cv::waitKey(10);
}
