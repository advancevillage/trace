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
    VideoController vcFrame("Preprocessor");
    cv::Mat orgframe;
    VideoController::cap.read(orgframe);
    //read first frame to initialize system
    const unsigned int base = 10;
    Preprocessor prepro(orgframe.rows, orgframe.cols, orgframe.channels(), orgframe.type(),base);

    while(VideoController::cap.read(orgframe) && !orgframe.empty()){

        //preprocessor
        prepro.Process(orgframe);
        if(prepro.GetAvailable()){
            //TO DO
            cv::Mat frame = prepro.GetFrame();
            vcFrame.SetCurFrame(frame);
            vcFrame.RegisterWindow();
            vcFrame.ShowWindow();
        }
        prepro.Push(orgframe);
        prepro.SetAvailable(false);
        //show window
        vcOrigin.SetCurFrame(orgframe);
        vcOrigin.RegisterWindow();
        vcOrigin.ShowWindow();
    }
    return (0);
}
