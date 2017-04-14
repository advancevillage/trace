#ifndef __OBJECT__TRACKER__
#define __OBJECT__TRACKER__

#ifndef __USED__OPENCV__
#define __USED__OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // __USED__OPENCV__

#ifndef __OBJECT__CONTROLLER__
#include "objectcontroller.h"
#endif // __OBJECT__CONTROLLER__

class OTracker{
protected:
    cv::Mat _curframe;
    ObjectController _objctl;

public:
    OTracker();
    OTracker(cv::Mat curframe, ObjectController& objctl);
    ~OTracker();

public:
    void Process(cv::Mat curframe, ObjectController& objctl);
    void ObjectTracker();
    cv::Mat GetFrame()const;

};

#endif // __OBJECT__TRACKER__
