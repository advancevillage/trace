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

ObjectArray ODetection::GetObjectArray(){
    return this->_objary;
}

ObjectController ODetection::GetObjectController(){
    return this->_objctl;
}

void ODetection::Process(cv::Mat mask){


}

void ODetection::ObjectDetection(cv::Mat mask){
    //TODO

}
