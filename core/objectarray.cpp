#ifndef __OBJECT__ARRAY__
#include "objectarray.h"
#endif // __OBJECT__ARRAY__

ObjectArray::ObjectArray(){

}

ObjectArray::ObjectArray(vector<Object>& objAry){
    this->_objAry = objAry;
}

ObjectArray::ObjectArray(ObjectArray& oa){
    this->_objAry = oa.GetObjectArray();
}

void ObjectArray::operator=(ObjectArray& oa){
    this->_objAry = oa.GetObjectArray();
}

void ObjectArray::operator=(vector<Object>& objAry){
    this->_objAry = objAry;
}

void ObjectArray::operator=(Object& obj){
    this->ClearAll();
    this->_objAry.push_back(obj);
}

vector<Object> ObjectArray::GetObjectArray()const{
    return this->_objAry;
}

void ObjectArray::Add(Object obj){
    this->_objAry.push_back(obj);
}

void ObjectArray::Add(vector<Object> objAry){
    for(vector<Object>::iterator it = objAry.begin(); it != objAry.end(); ++it){
        this->_objAry.push_back(*it);
    }
}

void ObjectArray::ClearAll(){
    this->_objAry.clear();
}

void ObjectArray::SetAllShow(const bool ishow){
    for(vector<Object>::iterator it = this->_objAry.begin(); it != this->_objAry.end(); ++it){
        it->SetShow(ishow);
    }
}

int ObjectArray::GetSize()const{
    return (int)this->_objAry.size();
}
