#ifndef __VIDEO_CONTROLLER__
#define __VIDEO_CONTROLLER__

#ifndef __USED_OPENCV__
#define __USED_OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif

#ifndef __USERD__STRING__
#define __USERD__STRING__
#include <string>
using namespace std;
#endif // __USERD__STRING__

class VideoController{
public:
    static cv::VideoCapture cap;

private:
    string _winid;
    cv::Mat _curframe;

public:
    explicit VideoController(const string winid);
    ~VideoController();

public:
    //window control
    void RegisterWindow()const;
    void ShowWindow();
    void SetCurFrame(const cv::Mat frame);


};


#endif // VIDEO_CONTROLLER
