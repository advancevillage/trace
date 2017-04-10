#ifndef __FOREGROUND__DETECTION__
#include "fgd.h"
#endif // __FOREGROUND__DETECTION__

FGDetection::FGDetection(const int rows, const int cols)
:_preframe(rows,cols, CV_8UC1, cv::Scalar::all(0)), _curframe(rows,cols,CV_8UC1,cv::Scalar::all(0)),_binImage(rows, cols, CV_8UC1, cv::Scalar::all(128))
,_rows(rows),_cols(cols),_limit(32), _avg(0), _variance(0.0){

}

FGDetection::FGDetection(const int rows, const int cols, const unsigned char limit)
:_preframe(rows,cols, CV_8UC1, cv::Scalar::all(0)), _curframe(rows,cols,CV_8UC1,cv::Scalar::all(0)),_binImage(rows, cols, CV_8UC1, cv::Scalar::all(128))
,_rows(rows),_cols(cols),_limit(limit),_avg(0), _variance(0.0){

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
//    this->ComputeAvg();
//    this->ComputeVariance();
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
//    string filename = "/home/tomato/repository/"+to_string(nthframe++)+".jpg";
//    cv::imwrite(filename, this->_binImage);
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

void FGDetection::ComputeAvg(){
    this->_avg = 0;
    unsigned int sum = 0;
    int rows = this->_rows;
    int cols = this->_cols;
    for(int i = 0; i < rows; ++i){
        uchar* binImageptr = this->_binImage.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j)
            sum += static_cast<unsigned int>(binImageptr[j]);
    }
    this->_avg = static_cast<unsigned char>(sum/(this->_rows*this->_cols));
}

void FGDetection::ComputeVariance(){
    this->_variance = 0.0;
    double sum = 0.0;
    int rows = this->_rows;
    int cols = this->_cols;
    double avg = static_cast<double>(this->_avg);
    for(int i = 0; i < rows; ++i){
        uchar* binImageptr = this->_binImage.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j){
            double value = static_cast<double>(binImageptr[j]);
            sum += (value-avg)*(value-avg);
        }
    }
    this->_variance = std::sqrt(sum/(this->_rows*this->_cols));
}
