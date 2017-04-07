#ifndef __OBJECT__NODE__
#include "objectnode.h"
#endif // __OBJECT__NODE__

ObjectNode::ObjectNode():Object(),_id(-1), _name("null"){

}

ObjectNode::ObjectNode(const int id, const string name):Object(),_id(id),_name(name){

}

ObjectNode::ObjectNode(const Object& obj, const int id, const string name):Object(obj), _id(id), _name(name){

}

ObjectNode::ObjectNode(const int x, const int y, const int width, const int height, const cv::Scalar color, const bool ishow, const int id, const string name):
    Object(x, y, width, height, color, ishow),_id(id), _name(name){

    }

ObjectNode::ObjectNode(const ObjectNode& objnode){
    this->_x = objnode.GetX();
    this->_y = objnode.GetY();
    this->_width = objnode.GetWidth();
    this->_height = objnode.GetHeight();
    this->_color = objnode.GetColor();
    this->_ishow = objnode.GetIshow();
    this->_id = objnode.GetID();
    this->_name = objnode.GetName();
}

ObjectNode::ObjectNode(ObjectNode& objnode){
    this->_x = objnode.GetX();
    this->_y = objnode.GetY();
    this->_width = objnode.GetWidth();
    this->_height = objnode.GetHeight();
    this->_color = objnode.GetColor();
    this->_ishow = objnode.GetIshow();
    this->_id = objnode.GetID();
    this->_name = objnode.GetName();
}

ObjectNode::ObjectNode(const Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetIshow();
    this->_id = -1;
    this->_name = "null";
}

ObjectNode::ObjectNode(Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetIshow();
    this->_id = -1;
    this->_name = "null";
}

void ObjectNode::operator=(const ObjectNode& objnode){
    this->_x = objnode.GetX();
    this->_y = objnode.GetY();
    this->_width = objnode.GetWidth();
    this->_height = objnode.GetHeight();
    this->_color = objnode.GetColor();
    this->_ishow = objnode.GetIshow();
    this->_id = objnode.GetID();
    this->_name = objnode.GetName();
}

void ObjectNode::operator=(ObjectNode& objnode){
    this->_x = objnode.GetX();
    this->_y = objnode.GetY();
    this->_width = objnode.GetWidth();
    this->_height = objnode.GetHeight();
    this->_color = objnode.GetColor();
    this->_ishow = objnode.GetIshow();
    this->_id = objnode.GetID();
    this->_name = objnode.GetName();
}

void ObjectNode::operator=(const Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetIshow();
    this->_id = -1;
    this->_name = "null";
}

void ObjectNode::operator=(Object& obj){
    this->_x = obj.GetX();
    this->_y = obj.GetY();
    this->_width = obj.GetWidth();
    this->_height = obj.GetHeight();
    this->_color = obj.GetColor();
    this->_ishow = obj.GetIshow();
    this->_id = -1;
    this->_name = "null";
}

ObjectNode::~ObjectNode(){

}

void ObjectNode::SetID(const int id){
    this->_id = id;
}

int ObjectNode::GetID()const{
    return this->_id;
}

void ObjectNode::SetName(const string name){
    this->_name = name;
}

string ObjectNode::GetName()const{
    return this->_name;
}
