#ifndef __PRE__PROCESSOR__
#include "preprocessor.h"
#endif // __PRE__PROCESSOR__

Preprocessor::Preprocessor(const int rows, const int cols, const int channels):_rows(rows),_cols(cols),_channels(channels), _base(2){

}

Preprocessor::Preprocessor(const int rows, const int cols, const int channels, const unsigned int base):_rows(rows),_cols(cols),_channels(channels),_base(base){

}

Preprocessor::~Preprocessor(){

}

int Preprocessor::GetSize()const{
    return (int)this->_orgframes.size();
}

bool Preprocessor::Full()const{
    return (this->GetSize() < this->_base)? false:true;
}


bool Preprocessor::Empty()const{
    return this->_orgframes.empty();
}

cv::Mat Preprocessor::GetFrame()const{
    return this->_frame;
}

void Preprocessor::SetBase(const unsigned int base){
    this->_base = base;
}

unsigned int Preprocessor::GetBase()const{
    return this->_base;
}

void Preprocessor::Add(cv::Mat orgframe){
    this->_orgframes.push_back(orgframe);
}

void Preprocessor::ImageAvg(){
    if(1 == this->_channels){

    }

    if(3 == this->_channels){

    }
}
