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
    this->ObjectDetection(mask);
    this->SetAllShow(true);
    this->_objctl = this->_objary;
}

void ODetection::ObjectDetection(cv::Mat mask){
    //TODO
    Object obj(100, 100, 100, 100,cv::Scalar(0,0,255));
    this->_objary.Add(obj);
    //
}
