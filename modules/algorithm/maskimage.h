#ifndef MASK_IMAGE
#define MASK_IMAGE

#ifndef USED_OPENCV
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // USED_OPENCV

#ifndef EXTEND_ALGORITHM
#include "exalgorithm.h"
#endif // EXTEND_ALGORITHM

class MaskImage{
private:
    cv::Mat mask;
    cv::Mat preFrame;
    cv::Mat curFrame;
    cv::Mat nextFrame;
    int rows;
    int cols;
    int type;

public:
    explicit MaskImage(const int rows, const int cols, const int type = CV_8UC1);
    ~MaskImage();

public:
    void SetPreFrame(cv::Mat frame);
    void SetCurFrame(cv::Mat frame);
    cv::Mat GetCurFrame()const;
    void SetNextFrame(cv::Mat frame);
    void SetMask(cv::Mat mask);
    cv::Mat GetMask()const;
    cv::Mat GenerateMask();
    void GenerateMaskImage(cv::Mat curframe, cv::Mat mask, cv::Mat& outframe);



};


#endif // MASK_IMAGE
