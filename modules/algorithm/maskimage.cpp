#ifndef MASK_IMAGE
#include "maskimage.h"
#endif // MASK_IMAGE

MaskImage::MaskImage(const int rows, const int cols, const int type):preFrame(rows, cols, type),curFrame(rows, cols, type),nextFrame(rows, cols, type),mask(rows, cols, type){
    this->rows = rows;
    this->cols = cols;
    this->type = type;
}

MaskImage::~MaskImage(){

}

void MaskImage::SetPreFrame(cv::Mat frame){
    this->preFrame = frame;
}

void MaskImage::SetCurFrame(cv::Mat frame){
    this->curFrame = frame;
}
cv::Mat MaskImage::GetCurFrame()const{
    return this->curFrame;
}

void MaskImage::SetNextFrame(cv::Mat frame){
    this->nextFrame =  frame;
}

void MaskImage::SetMask(cv::Mat mask){
    this->mask = mask;
}

cv::Mat MaskImage::GetMask()const{
    return this->mask;
}

cv::Mat MaskImage::GenerateMask(){
    cv::Mat pre_cur(this->rows, this->cols, this->type);
    cv::Mat cur_next(this->rows, this->cols, this->type);
    cv::Mat next_pre(this->rows, this->cols, this->type);
    ExAlgo::ImageSub(this->preFrame, this->curFrame, pre_cur);
    ExAlgo::ImageSub(this->curFrame, this->nextFrame, cur_next);
    ExAlgo::ImageSub(this->nextFrame, this->preFrame, next_pre);
    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->cols; ++j){
            mask.at<uchar>(i,j) = static_cast<uchar>(0.3*pre_cur.at<uchar>(i,j)+0.4*cur_next.at<uchar>(i,j)+0.3*next_pre.at<uchar>(i,j));
        }
    }
    return this->mask;
}

void MaskImage::GenerateMaskImage(cv::Mat curframe, cv::Mat mask, cv::Mat& outframe){
    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->cols; ++j){
            outframe.at<uchar>(i,j) = static_cast<uchar>(curframe.at<uchar>(i,j) * mask.at<uchar>(i,j) / 256);
        }
    }
}

