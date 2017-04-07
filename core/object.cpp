#ifndef __OBJECT__
#include "object.h"
#endif // OBJECT
Object::Object():_x(0), _y(0), _width(0), _height(0),_color(cv::Scalar(255,0,0)),_ishow(false){

}

Object::Object(int x, int y, int width, int height, cv::Scalar color, bool ishow):_x(x),_y(y),_width(width),_height(height),_color(color),_ishow(ishow){

}

Object::Object(Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetShow();
}

Object::Object(const Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetShow();
}

void Object::operator=(Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetShow();
}

void Object::operator=(const Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetShow();
}

Object::~Object(){

}

void Object::SetX(const int x){
    this->_x = x;
}

int Object::GetX()const{
    return this->_x;
}

void Object::SetY(const int y){
    this->_y = y;
}

int Object::GetY()const{
    return this->_y;
}

void Object::SetWidth(const int width){
    this->_width = width;
}

int Object::GetWidth()const{
    return this->_width;
}

void Object::SetHeight(const int height){
    this->_height = height;
}

int Object::GetHeight()const{
    return this->_height;
}

void Object::SetColor(const cv::Scalar color){
    this->_color = color;
}

cv::Scalar Object::GetColor()const{
    return this->_color;
}

void Object::SetShow(const bool ishow){
    this->_ishow = ishow;
}

bool Object::GetShow()const{
    return this->_ishow;
}

void Object::SetPoint(cv::Point pos){
    this->_x = pos.x;
    this->_y = pos.y;
}

void Object::SetPoint(const int x, const int y){
    this->_x = x;
    this->_y = y;
}

cv::Point Object::GetPoint()const{
    return cv::Point(this->_x, this->_y);
}
