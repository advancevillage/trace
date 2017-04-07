#include "videocontroller.h"
#include "object.h"
#include "objectnode.h"
#include "objectarray.h"
#include "objectcontroller.h"
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
    ObjectNode objnode1(obj1, 1, "people");
    ObjectNode objnode2 = objnode1;
    ObjectNode objnode3 = obj1;
    ObjectArray oa;
    oa.Add(obj1);
    oa.Add(obj2);
    int size = oa.GetSize();
    oa.SetAllShow(false);
    oa.ClearAll();
    size = oa.GetSize();

    ObjectController oc;
    oc.Add(objnode1);
    oc.Add(objnode2);
    oc.Add(objnode3);
    size = oc.GetSize();
    oc.ClearAll();
    size = oc.GetSize();

    return 0;
}
