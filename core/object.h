#ifndef __OBJECT__
#define __OBJECT__

#ifndef __USED_OPENCV__
#define __USED_OPENCV__
#include <opencv2/opencv.hpp>
using namespace cv;
#endif

class Object{
protected:
    int _x;
    int _y;
    int _width;
    int _height;
    cv::Scalar _color;
    bool _ishow;

public:
    Object();
    Object(int x, int y, int width, int height, cv::Scalar color, bool ishow = false);
    Object(Object& obj);
    Object(const Object& obj);
    ~Object();
    void operator=(Object& obj);
    void operator=(const Object& obj);

public:
    void SetX(const int x);
    int GetX()const;
    void SetY(const int y);
    int GetY()const;
    void SetWidth(const int width);
    int GetWidth()const;
    void SetHeight(const int height);
    int GetHeight()const;
    void SetColor(const cv::Scalar color);
    cv::Scalar GetColor()const;
    void SetShow(const bool ishow);
    bool GetShow()const;
    void SetPoint(cv::Point pos);
    void SetPoint(const int x, const int y);
    cv::Point GetPoint()const;


};


#endif // OBJECT
