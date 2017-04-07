#ifndef __OBJECT__CONTROLLER__
#include "objectcontroller.h"
#endif // __OBJECT__CONTROLLER__

ObjectController::ObjectController(){

}

ObjectController::ObjectController(ObjectController& objCtl){
    this->_objnodeAry = objCtl.GetObjectNodeArray();
}

ObjectController::ObjectController(ObjectArray& oa){
   for(int i = 0; i < oa.GetSize(); ++i){
        this->_objnodeAry.push_back(ObjectNode(oa.GetObjectArray()[i]));
   }
}

ObjectController::ObjectController(deque<ObjectNode>& objnodeAry){
    this->_objnodeAry = objnodeAry;
}

ObjectController::ObjectController(vector<Object>& objAry){
    for(int i = 0; i < (int)objAry.size(); ++i){
        this->_objnodeAry.push_back(ObjectNode(objAry[i]));
    }
}

ObjectController::~ObjectController(){

}

void ObjectController::operator=(ObjectController& oc){
    this->_objnodeAry = oc.GetObjectNodeArray();
}

void ObjectController::operator=(ObjectArray& oa){
    this->ClearAll();
    for(int i = 0; i < oa.GetSize(); ++i){
        this->_objnodeAry.push_back(ObjectNode(oa.GetObjectArray()[i]));
    }
}

void ObjectController::operator=(deque<ObjectNode>& objnodeAry){
    this->_objnodeAry = objnodeAry;
}

void ObjectController::operator=(vector<Object>& objAry){
    this->ClearAll();
    for(int i = 0; i < (int)objAry.size(); ++i){
        this->_objnodeAry.push_back(ObjectNode(objAry[i]));
    }
}

void ObjectController::operator=(ObjectNode& objnode){
    this->ClearAll();
    this->_objnodeAry.push_back(objnode);
}

void ObjectController::operator=(Object& obj){
    this->ClearAll();
    this->_objnodeAry.push_back(ObjectNode(obj));
}

deque<ObjectNode> ObjectController::GetObjectNodeArray()const{
    return this->_objnodeAry;
}

int ObjectController::GetSize()const{
    return (int)this->_objnodeAry.size();
}

void ObjectController::ClearAll(){
    this->_objnodeAry.clear();
}

void ObjectController::Add(ObjectNode objnode){
    this->_objnodeAry.push_back(objnode);
}

void ObjectController::Add(Object obj){
    this->_objnodeAry.push_back(ObjectNode(obj));
}

void ObjectController::Add(deque<ObjectNode> objnodeAry){
    for(deque<ObjectNode>::iterator it = objnodeAry.begin(); it != objnodeAry.end(); ++it){
        this->_objnodeAry.push_back(*it);
    }
}

void ObjectController::Add(vector<Object> objAry){
    for(vector<Object>::iterator it = objAry.begin(); it != objAry.end(); ++it){
        this->_objnodeAry.push_back(ObjectNode(*it));
    }
}

void ObjectController::SetAllShow(const bool ishow){
    for(deque<ObjectNode>::iterator it = this->_objnodeAry.begin(); it != this->_objnodeAry.end(); ++it){
        it->SetShow(ishow);
    }
}
