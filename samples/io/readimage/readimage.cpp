#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void Sharpen(const Mat& inputImage, Mat& outputImage);

int main(int argc, char* argv[]){

    const char* filename = argc >= 2? argv[1]:"/home/river/advancevillage/res/test01.jpg";
    Mat src, dst0, dst1;

    if(argc >= 3 && !strcmp("G", argv[2])){
        src = imread(filename, IMREAD_GRAYSCALE);
    }else{
        src = imread(filename, IMREAD_COLOR);
    }

    if(src.empty()){
        cerr << "Can't open image [" << filename <<"]"<<endl;
    }
    
    namedWindow("Input", WINDOW_AUTOSIZE);
    namedWindow("Output", WINDOW_AUTOSIZE);

    imshow("Input", src);
    double t = (double)getTickCount();
    Sharpen(src, dst0);
    t = ((double)getTickCount()-t)/getTickFrequency();
    cout << "Hand written function times passed in seconds: " << t << endl;
    imshow("OUtput",dst0);
    Mat kernel = (Mat_<char>(3,3) << 0, -1, 0,
                                    -1, 5, -1,
                                    0, -1, 0);
    t  = (double)getTickCount();
    filter2D(src, dst1, src.depth(), kernel);
    t = ((double)getTickCount()-t)/getTickFrequency();
    cout << "Build-in filter2D time passed in second: " << t << endl;
    imshow("Output", dst1);
    waitKey();

    return 0;
}

void Sharpen(const Mat& inputImage, Mat& outputImage){
    CV_Assert(inputImage.depth() == CV_8U);
    const int nChannels = inputImage.channels();
    outputImage.create(inputImage.size(), inputImage.type());
    for(int j = 1; j < inputImage.rows -1; ++j){
        const uchar* previous = inputImage.ptr<uchar>(j-1);
        const uchar* current = inputImage.ptr<uchar>(j);
        const uchar* next = inputImage.ptr<uchar>(j+1);
        uchar* temp = outputImage.ptr<uchar>(j);
        for(int i = nChannels; i < nChannels*(inputImage.cols-1); ++i){
            *temp++ = saturate_cast<uchar>(5*current[i] 
                        - current[i-nChannels] 
                        - current[i+nChannels]
                        - previous[i]
                        - next[i]);
        }
    }
    outputImage.row(0).setTo(Scalar(0));
    outputImage.row(outputImage.rows-1).setTo(Scalar(0));
    outputImage.col(0).setTo(Scalar(0));
    outputImage.col(outputImage.cols-1).setTo(Scalar(0));
}






















