#include "videocontroller.h"
#include "exalgorithm.h"
//camera id
#define CAMERA_ID 1
#define BINARY_IMAGE_SEQ_COUNT 2
#define IMAGE_SEQ_COUNT 4

//#include <iostream>
//using namespace std;

cv::VideoCapture VideoController::cap(CAMERA_ID);

int main(int argc, char* argv[]){
    VideoController videoCtl_Origin("origin");
    VideoController videoCtl_Canny("canny");
    VideoController videoCtl_Hist("hist");
    VideoController videoCtl_BinImage("BinaryImage");

    deque<cv::Mat> imageSeq;
    deque<cv::Mat> binImageSeq;

    unsigned int imageSeqCount = 0;
    unsigned int binImageSeqCount = 0;

    if(VideoController::cap.isOpened()){
        while(true){
            cv::Mat origin_frame;
            VideoController::cap.read(origin_frame);
            cv::cvtColor(origin_frame, origin_frame, COLOR_RGB2GRAY);
//            int channels = frame.channels();
            cv::Mat frame(origin_frame.rows, origin_frame.cols, CV_8UC1);
            if(imageSeqCount < IMAGE_SEQ_COUNT){
                imageSeq.push_back(origin_frame);
            }else{
                ExAlgo::ImageAvgDenoing(imageSeq, frame);
                imageSeq.pop_front();
                imageSeq.pop_front();
                imageSeqCount = 1;
                //current frame = 4 origin frame
                cv::equalizeHist(frame, frame);
                videoCtl_Canny.SetCurFrame(frame);
                videoCtl_Canny.RegisterWindow();
                videoCtl_Canny.ShowWindow();

                cv::Mat hist;
                cv::Mat histImg;
                ExAlgo::CalcGrayImageHist(frame, hist);
                histImg = ExAlgo::GetGrayImageHistImage(hist);
                videoCtl_Hist.SetCurFrame(histImg);
                videoCtl_Hist.RegisterWindow();
                videoCtl_Hist.ShowWindow();

                if(binImageSeqCount < BINARY_IMAGE_SEQ_COUNT){
                    binImageSeq.push_back(frame);
                }else{
                    cv::Mat output(binImageSeq[0].rows, binImageSeq[0].cols, CV_8U);
                    ExAlgo::ImageSub(binImageSeq[0], binImageSeq[1], output);
                    const unsigned char T = 64;
                    ExAlgo::BinaryDivisionImage(output, output, T);

                    videoCtl_BinImage.SetCurFrame(output);
                    videoCtl_BinImage.RegisterWindow();
                    videoCtl_BinImage.ShowWindow();

                    binImageSeq.pop_front();
                    binImageSeqCount = 0;
                }
                binImageSeqCount++;

            }
            //get current frame
            videoCtl_Origin.SetCurFrame(origin_frame);
            //register window name
            videoCtl_Origin.RegisterWindow();
            //window show
            videoCtl_Origin.ShowWindow();

            imageSeqCount++;
        }

    }
    return 0;
}
