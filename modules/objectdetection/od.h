#ifndef __OBJECT__DETECTION__
#define __OBJECT__DETECTION__

#ifndef __OBJECT__ARRAY__
#include "objectarray.h"
#endif // __OBJECT__ARRAY__

#ifndef __OBJECT__CONTROLLER__
#include "objectcontroller.h"
#endif // __OBJECT__CONTROLLER__

#ifndef __USED_OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // __USED_OPENCV__

class ODetection{
protected:
    ObjectArray _objary;
    ObjectController _objctl;

public:
    ODetection();
    ~ODetection();

public:
    void Process(cv::Mat mask);
    void SetAllShow(const bool ishow);
    void ObjectDetection(cv::Mat mask);
    ObjectArray GetObjectArray();
    ObjectController GetObjectController();
};



#endif // __OBJECT__DETECTION__
