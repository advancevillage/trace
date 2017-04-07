#include "videocontroller.h"
#include "object.h"
#include "objectnode.h"
#include "objectarray.h"
#include "objectcontroller.h"
#include "preprocessor.h"
//camera id
#define CAMERA_ID 1

cv::VideoCapture VideoController::cap(CAMERA_ID);

int main(int argc, char* argv[]){

    if(!VideoController::cap.isOpened())
        return (-1);
    VideoController vcOrigin("origin");
    cv::Mat orgframe;

    //read first frame to initialize system
    VideoController::cap.read(orgframe);


    while(VideoController::cap.read(orgframe) && !orgframe.empty()){

        //preprocessor

        //show window
        vcOrigin.SetCurFrame(orgframe);
        vcOrigin.RegisterWindow();
        vcOrigin.ShowWindow();
    }
    return (0);
}
