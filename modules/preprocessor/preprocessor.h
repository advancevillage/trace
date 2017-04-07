#ifndef __PRE__PROCESSOR__
#define __PRE__PROCESSOR__

#ifndef __USED_OPENCV__
#include <opencv2/opencv.hpp>
#endif // __USED_OPENCV__

#ifndef __USED__DEQUE__
#define __USED__DEQUE__
#include <deque>
using namespace std;
#endif // __USED__DEQUE__

class Preprocessor{
protected:
    deque<cv::Mat> _orgframes;
    cv::Mat _frame;
    int _rows;
    int _cols;
    int _channels;
    unsigned int _base;

public:
    explicit Preprocessor(const int rows, const int cols, const int channels);
    explicit Preprocessor(const int rows, const int cols, const int channels, const unsigned int base);
    ~Preprocessor();

public:
    bool Full()const;
    bool Empty()const;

};

#endif // __PRE_PROCESSOR__
