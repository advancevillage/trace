#include "videocontroller.h"
#include "object.h"
#include "objectnode.h"
#include "objectarray.h"
#include "objectcontroller.h"
#include "preprocessor.h"
#include "fgd.h"
#include "od.h"
//camera id
#define CAMERA_ID 0

cv::VideoCapture VideoController::cap(CAMERA_ID);

int main(int argc, char* argv[]){

    if(!VideoController::cap.isOpened())
        return (-1);
    VideoController vcOrigin("origin");
    VideoController vcFrame("foreground detection");
    cv::Mat orgframe;
    VideoController::cap.read(orgframe);
    //read first frame to initialize system
    const unsigned int base = 8;
    const unsigned char limit = 30;
    Preprocessor prepro(orgframe.rows, orgframe.cols, orgframe.channels(), orgframe.type(),base);
    FGDetection  fgd(orgframe.rows, orgframe.cols, limit);
    while(VideoController::cap.read(orgframe) && !orgframe.empty()){
        //preprocessor
        prepro.Process(orgframe);
        if(prepro.GetAvailable()){
            //TO DO
            cv::Mat frame = prepro.GetFrame();
            fgd.Process(frame);
            frame = fgd.GetFDMask();
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
