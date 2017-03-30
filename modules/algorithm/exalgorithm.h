#ifndef EXTEND_ALOGRITHM
#define EXTEND_ALGORITHM

#ifndef USED_OPENCV
#include <opencv2/opencv.hpp>
using namespace cv;
#endif // USED_OPENCV

#include <deque>
using namespace std;

class ExAlgo{
public:
    static void ImageAvgDenoising(deque<cv::Mat> imageSeq, cv::Mat image);

    static void CalcGrayImageHist(cv::Mat image, cv::Mat& hist);

    static cv::Mat GetGrayImageHistImage(cv::Mat hist);

    static void BinaryDivisionImage(cv::Mat input, cv::Mat& output, unsigned char T);

    static void ImageSub(cv::Mat fir, cv::Mat sec, cv::Mat& output);

};
#endif // EXTEND_ALOGRITHM
