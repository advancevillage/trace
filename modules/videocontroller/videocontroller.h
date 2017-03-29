#ifndef VIDEO_CONTROLLER
#define VIDEO_CONTROLLER

#ifndef USED_OPENCV
#define USED_OPENCV
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // USERD_OPENCV

#include <string>
using namespace std;

class VideoController{
public:
    static cv::VideoCapture cap;

private:
    string win_id;
    cv::Mat cur_frame;

public:
    explicit VideoController(const string w_id);
    ~VideoController();

public:
    //window control
    void RegisterWindow()const;
    void ShowWindow();
    void SetCurFrame(const cv::Mat frame);


};


#endif // VIDEO_CONTROLLER
