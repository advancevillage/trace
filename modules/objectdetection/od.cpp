#ifndef __OBJECT__DETECTION__
#include "od.h"
#endif // __OBJECT__DETECTION__

ODetection::ODetection(){

}

ODetection::~ODetection(){

}

void ODetection::SetAllShow(const bool ishow){
    this->_objary.SetAllShow(ishow);
}

ObjectArray& ODetection::GetObjectArray(){
    return this->_objary;
}

ObjectController& ODetection::GetObjectController(){
    return this->_objctl;
}

void ODetection::Process(cv::Mat mask){
    this->_objary.ClearAll();
    this->ObjectDetection(mask);
    this->SetAllShow(true);
    this->_objctl = this->_objary;
}

void ODetection::ObjectDetection(cv::Mat mask){
    //TODO
    int x = 0, y = 0, S =  1;
    const int width = 15;
    const int height = 15;
    const unsigned char num = 255;
    int rows = mask.rows;
    int cols = mask.cols;
    int64_t xS = 0, yS = 0;
    for(int i = 0; i < rows; ++i){
        uchar* data = mask.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j){
            int value = 0;
            if(num == *data++) value = 1;
            S += value;
            xS += static_cast<int64_t>(j*value);
            yS += static_cast<int64_t>(i*value);
        }
    }
    x = static_cast<int>(xS/S);
    y = static_cast<int>(yS/S);
    x = x > (rows-width)? (rows-width):x;
    y = y > (cols-height)? (cols-height):y;
    Object obj(x, y, width, height,cv::Scalar(0,0,255));
    this->_objary.Add(obj);
    //
}
