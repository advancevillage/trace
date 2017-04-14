#ifndef __OBJECT__TRACKER__
#include "ot.h"
#endif // __OBJECT__TRACKER__

OTracker::OTracker(){

}

OTracker::OTracker(cv::Mat curframe, ObjectController& objctl):_curframe(curframe), _objctl(objctl){

}

OTracker::~OTracker(){

}

void OTracker::Process(cv::Mat curframe, ObjectController& objctl){
    this->_objctl.ClearAll();
    this->_objctl = objctl;
    this->_curframe = curframe;
    this->ObjectTracker();
}

void OTracker::ObjectTracker(){
    for(int i = 0; i < this->_objctl.GetSize(); ++i){
        ObjectNode objnode = this->_objctl.GetObjectNodeArray().at(i);
        cv::Point fir =  objnode.GetPoint();
        cv::Point sec(objnode.GetX()+objnode.GetWidth(), objnode.GetY()+objnode.GetHeight());
        cv::rectangle(this->_curframe, fir, sec, objnode.GetColor());
    }
}

cv::Mat OTracker::GetFrame()const{
    return this->_curframe;
}
