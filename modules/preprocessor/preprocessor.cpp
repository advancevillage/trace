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

void Preprocessor::Push(cv::Mat orgframe){
    this->_orgframes.push_back(orgframe);
}

void Preprocessor::Pop(const int nc){
    for(int i =0; !this->Empty() && i < nc; ++i)
        this->_orgframes.pop_front();
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
    vector<uchar*> imagesptr;
    for(int i = 0; i < rows; ++i){
        for(unsigned int base = 0; base < this->GetSize(); ++base){
            imagesptr.push_back(this->_orgframes.at(base).ptr<uchar>(i));
        }
        uchar* data = this->_frame.ptr<uchar>(i);
        for(int j = 0; j < cols; ++j){
            unsigned int sum =0;
            for(unsigned int base = 0; base < this->GetSize(); ++base){
                sum += static_cast<unsigned int>(imagesptr.at(base)[j]);
            }
            *data++ = static_cast<uchar>(sum/this->GetSize());
        }
        imagesptr.clear();
    }
    //cv::GaussianBlur(this->_frame, this->_frame, cv::Size(3,3),0,0);
}

void Preprocessor::Process(cv::Mat& orgframe){
    if(!this->Full()) return;
    this->ImageAvg();
    this->_available = true;
//    this->ClearAll();
    this->Pop(this->_base/4);
}
