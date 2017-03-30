#include "videocontroller.h"
#include "exalgorithm.h"
#include "maskimage.h"
//camera id
#define CAMERA_ID 1
#define BINARY_IMAGE_SEQ_COUNT 3
#define IMAGE_SEQ_COUNT 4

//#include <iostream>
//using namespace std;

cv::VideoCapture VideoController::cap(CAMERA_ID);

int main(int argc, char* argv[]){
    VideoController videoCtl_Origin("origin");
    VideoController videoCtl_Denoisng("denoising");
    VideoController videoCtl_Hist("hist");
    VideoController videoCtl_BinImage("BinaryImage");
    VideoController videoCtl_ImageSeg("ImageSegmentation");

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
            MaskImage maskImage(origin_frame.rows, origin_frame.cols, CV_8UC1);
            if(imageSeqCount < IMAGE_SEQ_COUNT){
                imageSeq.push_back(origin_frame);
            }else{
                ExAlgo::ImageAvgDenoising(imageSeq, frame);
                imageSeq.pop_front();
                imageSeq.pop_front();
                imageSeqCount = 1;
                //current frame = 4 origin frame
                //cv::equalizeHist(frame, frame);
                videoCtl_Denoisng.SetCurFrame(frame);
                videoCtl_Denoisng.RegisterWindow();
                videoCtl_Denoisng.ShowWindow();

                //to test
                cv::Mat hist;
                cv::Mat histImg;
                ExAlgo::CalcGrayImageHist(frame, hist);
                histImg = ExAlgo::GetGrayImageHistImage(hist);
                videoCtl_Hist.SetCurFrame(histImg);
                videoCtl_Hist.RegisterWindow();
                videoCtl_Hist.ShowWindow();
                //to test

                if(binImageSeqCount < BINARY_IMAGE_SEQ_COUNT){
                    binImageSeq.push_back(frame);
                }else{
                    cv::Mat binImage(origin_frame.rows, origin_frame.cols, CV_8UC1);
                    maskImage.SetPreFrame(binImageSeq[0]);
                    maskImage.SetCurFrame(binImageSeq[1]);
                    maskImage.SetNextFrame(binImageSeq[2]);
                    binImage = maskImage.GenerateMask();
                    const unsigned char T = 28;
                    ExAlgo::BinaryDivisionImage(binImage, binImage, T);
                    maskImage.SetMask(binImage);

                    videoCtl_BinImage.SetCurFrame(binImage);
                    videoCtl_BinImage.RegisterWindow();
                    videoCtl_BinImage.ShowWindow();

                    cv::Mat imageSeg(origin_frame.rows, origin_frame.cols, CV_8UC1);
                    maskImage.GenerateMaskImage(maskImage.GetCurFrame(), maskImage.GetMask(), imageSeg);

                    videoCtl_ImageSeg.SetCurFrame(imageSeg);
                    videoCtl_ImageSeg.RegisterWindow();
                    videoCtl_ImageSeg.ShowWindow();

//                   // to test
//                    cv::Mat hist;
//                    cv::Mat histImg;
//                    ExAlgo::CalcGrayImageHist(output, hist);
//                    histImg = ExAlgo::GetGrayImageHistImage(hist);
//                    videoCtl_Hist.SetCurFrame(histImg);
//                    videoCtl_Hist.RegisterWindow();
//                    videoCtl_Hist.ShowWindow();
//                   // to test

                    binImageSeq.pop_front();
                    binImageSeqCount = 1;
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
