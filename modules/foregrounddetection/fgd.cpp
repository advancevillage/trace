#ifndef __FOREGROUND__DETECTION__
#include "fgd.h"
#endif // __FOREGROUND__DETECTION__

FGDetection::FGDetection(const int rows, const int cols)
:_preframe(rows,cols, CV_8UC1, cv::Scalar::all(0)), _curframe(rows,cols,CV_8UC1,cv::Scalar::all(0)),_binImage(rows, cols, CV_8UC1, cv::Scalar::all(128))
,_rows(rows),_cols(cols),_limit(32){

}

FGDetection::FGDetection(const int rows, const int cols, const unsigned char limit)
:_preframe(rows,cols, CV_8UC1, cv::Scalar::all(0)), _curframe(rows,cols,CV_8UC1,cv::Scalar::all(0)),_binImage(rows, cols, CV_8UC1, cv::Scalar::all(128))
,_rows(rows),_cols(cols),_limit(limit){

}

FGDetection::~FGDetection(){

}

void FGDetection::GrayProcess(cv::Mat frame){
    cv::cvtColor(frame, this->_curframe, COLOR_RGB2GRAY);
}

void FGDetection::FramesDiff(){
    int channels = this->_curframe.channels();
    int rows = this->_rows;
    int cols = this->_cols * channels;
    for(int i = 0; i < rows; ++i){
        uchar* curframeptr = this->_curframe.ptr<uchar>(i);
        uchar* preframeptr = this->_preframe.ptr<uchar>(i);
        uchar* binImageptr = this->_binImage.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j){
            if(curframeptr[j] > preframeptr[j]){
                binImageptr[j] = curframeptr[j] - preframeptr[j];
            }else{
                binImageptr[j] = preframeptr[j] - curframeptr[j];
            }
        }
    }
}

void FGDetection::Binarization(){
    int channels = this->_curframe.channels();
    int rows = this->_rows;
    int cols = this->_cols *channels;
    for(int i = 0; i < rows; ++i){
        uchar* binImageptr = this->_binImage.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j){
            if(binImageptr[j] < this->_limit){
                binImageptr[j] = static_cast<uchar>(0);
            }else{
                binImageptr[j] = static_cast<uchar>(255);
            }
        }
    }
    cv::medianBlur(this->_binImage, this->_binImage, 3);
}

void FGDetection::SetLimit(const unsigned char limit){
    this->_limit = limit;
}

unsigned char FGDetection::GetLimit()const{
    return this->_limit;
}

cv::Mat FGDetection::GetFDMask()const{
    return this->_binImage;
}

void FGDetection::Process(cv::Mat frame){
    this->GrayProcess(frame);
    this->FramesDiff();
    this->Binarization();
    this->_curframe.copyTo(this->_preframe);
}
