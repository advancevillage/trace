#ifndef __PRE__PROCESSOR__
#define __PRE__PROCESSOR__

#ifndef __USED__OPENCV__
#define __USED__OPENCV__
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
    int _type;
    unsigned int _base;
    bool _available;

public:
    explicit Preprocessor(const int rows, const int cols, const int channels, const int type);
    explicit Preprocessor(const int rows, const int cols, const int channels, const int type,const unsigned int base);
    ~Preprocessor();

public:
    bool Full()const;
    bool Empty()const;
    unsigned int GetSize()const;
    void Push(cv::Mat orgframe);
    void Pop(const int nc = 2);
    void SetBase(const unsigned int base);
    void SetAvailable(const bool available);
    bool GetAvailable()const;
    void ClearAll();
    unsigned int GetBase()const;
    void ImageAvg();
    cv::Mat GetFrame()const;
    void Process(cv::Mat& orgframe);
};

#endif // __PRE_PROCESSOR__
