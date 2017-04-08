#ifndef __PRE__PROCESSOR__
#include "preprocessor.h"
#endif // __PRE__PROCESSOR__

Preprocessor::Preprocessor(const int rows, const int cols, const int channels, const int type)
:_frame(rows, cols, type, cv::Scalar::all(0))
,_rows(rows),_cols(cols),_channels(channels),_type(type), _base(2),_available(false){

}

Preprocessor::Preprocessor(const int rows, const int cols, const int channels, const int type, const unsigned int base)
:_frame(rows, cols, type, cv::Scalar::all(0))
,_rows(rows),_cols(cols),_channels(channels),_type(type),_base(base),_available(false){

}

Preprocessor::~Preprocessor(){

}

unsigned int Preprocessor::GetSize()const{
    return this->_orgframes.size();
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

void Preprocessor::SetAvailable(const bool available){
    this->_available = available;
}

bool Preprocessor::GetAvailable()const{
    return this->_available;
}

void Preprocessor::ClearAll(){
    this->_orgframes.clear();
}

void Preprocessor::ImageAvg(){
    int rows = this->_rows;
    int cols = this->_cols * this->_channels;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){

        }
    }
}

void Preprocessor::Process(cv::Mat& orgframe){
    if(!this->Full()) return;
    this->ImageAvg();
    this->_available = true;
    this->ClearAll();
}
