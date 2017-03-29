#ifndef EXTEND_ALGORITHM
#include "exalgorithm.h"
#endif // EXTEND_ALGORITHM

void ExAlgo::ImageAvgDenoing(deque<cv::Mat> imageSeq, cv::Mat image){
    int rows = imageSeq[0].rows;
    int cols = imageSeq[0].cols;
    int counts = imageSeq.size();
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            int value = 0;
            for(int k = 0; k < counts; ++k){
                value += imageSeq[k].at<uchar>(i,j);
            }
            image.at<uchar>(i,j) = (uchar)(value/counts);
        }
    }
}

void ExAlgo::CalcGrayImageHist(cv::Mat image, cv::Mat& hist){
    const int nImages = 1;
    const int dims = 1;
    const int channels[1] = {0};
    const int histSize[1] = {256};
    float hrange[2] = {0, 255};
    const float* range[1] = {hrange};
    cv::calcHist(&image, nImages, channels, cv::Mat(), hist, dims, histSize, range);
}


cv::Mat ExAlgo::GetGrayImageHistImage(cv::Mat hist){
    double minValue = 0.0;
    double maxValue = 0.0;
    cv::minMaxLoc(hist, &minValue, &maxValue, 0, 0);

    int histSize = hist.rows;
    cv::Mat histImg(histSize, histSize, CV_8U, cv::Scalar(255));

    int hpt = static_cast<int>(0.9*histSize);

    for(int h = 0; h < histSize; ++h){
        float binVal = hist.at<float>(h);
        int intensity = static_cast<int>(binVal*hpt/maxValue);
        cv::line(histImg, cv::Point(h, histSize), cv::Point(h, histSize-intensity),cv::Scalar::all(0));
    }
    return histImg;
}


void ExAlgo::BinaryDivisionImage(cv::Mat input, cv::Mat& output, unsigned char T){
    int rows = input.rows;
    int cols = input.cols;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(input.at<uchar>(i,j) < T) output.at<uchar>(i,j) = 0;
            else output.at<uchar>(i,j) = 255;
        }
    }
}


void ExAlgo::ImageSub(cv::Mat fir, cv::Mat sec, cv::Mat& output){
    int rows = fir.rows;
    int cols = fir.cols;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            unsigned char firPixVal = fir.at<uchar>(i,j);
            unsigned char secPixVal = sec.at<uchar>(i,j);
            if(firPixVal >= secPixVal){
                output.at<uchar>(i,j) = firPixVal - secPixVal;
            }else{
                output.at<uchar>(i,j) = secPixVal - firPixVal;
            }
        }
    }
}
