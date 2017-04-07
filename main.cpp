#include "videocontroller.h"
#include "object.h"
//camera id
#define CAMERA_ID 1

cv::VideoCapture VideoController::cap(CAMERA_ID);

int main(int argc, char* argv[]){
    VideoController videoCtl_Origin("origin");


//    if(VideoController::cap.isOpened()){
//        while(true){
//            cv::Mat origin_frame;
//            VideoController::cap.read(origin_frame);
//
//            //get current frame
//            videoCtl_Origin.SetCurFrame(origin_frame);
//            //register window name
//            videoCtl_Origin.RegisterWindow();
//            //window show
//            videoCtl_Origin.ShowWindow();
//
////            imageSeqCount++;
//        }
//
//    }
    Object obj1(10, 10, 100, 100, cv::Scalar(0,255,0), true);
    Object obj2 = obj1;
    Object obj3;
    obj3 = obj2;

    return 0;
}
