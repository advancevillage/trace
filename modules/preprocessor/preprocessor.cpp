#ifndef __PRE__PROCESSOR__
#include "preprocessor.h"
#endif // __PRE__PROCESSOR__

Preprocessor::Preprocessor(const int rows, const int cols, const int channels):_rows(rows),_cols(cols),_channels(channels), _base(2){

}

Preprocessor::Preprocessor(const int rows, const int cols, const int channels, const unsigned int base):_rows(rows),_cols(cols),_channels(channels),_base(base){

}

Preprocessor::~Preprocessor(){

}

