#include "videocontroller.h"
#include "object.h"
#include "objectnode.h"
#include "objectarray.h"
#include "objectcontroller.h"
#include "preprocessor.h"
#include "fgd.h"
#include "od.h"
#include "ot.h"

//camera id
#define CAMERA_ID 1

cv::VideoCapture VideoController::cap(CAMERA_ID);
unsigned int FGDetection::nthframe = 0;

int main(int argc, char* argv[]){

    if(!VideoController::cap.isOpened())
        return (-1);
    VideoController vcOrigin("origin");
    VideoController vcFrame("trace");
    cv::Mat orgframe;
    VideoController::cap.read(orgframe);
    //read first frame to initialize system
    const unsigned int base = 8;
    const unsigned char limit = 64;
    Preprocessor prepro(orgframe.rows, orgframe.cols, orgframe.channels(), orgframe.type(),base);
    FGDetection  fgd(orgframe.rows, orgframe.cols, limit);
    ODetection od;
    OTracker ot;
    while(VideoController::cap.read(orgframe) && !orgframe.empty()){
        //preprocessor
        prepro.Process(orgframe);
        if(prepro.GetAvailable()){
            //TO DO
            cv::Mat curframe = prepro.GetFrame();
            fgd.Process(curframe);
            cv::Mat mask = fgd.GetFDMask();
            //object detection
            od.Process(mask);
            //object tracker
            ot.Process(curframe, od.GetObjectController());
            curframe = ot.GetFrame();
            vcFrame.SetCurFrame(curframe);
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
