#ifndef __FOREGROUND__DETECTION__
#define __FOREGROUND__DETECTION__

#ifndef __USED__OPENCV__
#define __USED__OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // __USED_OPENCV__

class FGDetection{
protected:
    cv::Mat _preframe;
    cv::Mat _curframe;
    cv::Mat _binImage;
    int _rows;
    int _cols;
    unsigned char _limit;

public:
    explicit FGDetection(const int rows, const int cols);
    explicit FGDetection(const int rows, const int cols, const unsigned char limit);
    ~FGDetection();

public:
    void GrayProcess(cv::Mat frame);
    void FramesDiff();
    void Process(cv::Mat frame);
    void Binarization();
    void SetLimit(const unsigned char limit);
    unsigned char GetLimit()const;
    cv::Mat GetFDMask()const;


};

#endif // __FOREGROUND__DETECTION__
