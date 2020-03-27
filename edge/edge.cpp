#include<iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	
	while (1) {
		Mat frame;
		cap >> frame;
		Mat dstMat;
		Mat result;
		threshold(frame, result, 0, 255, THRESH_BINARY);
		Sobel(result, dstMat, CV_16SC1, 1, 0, 3);
		Sobel(result, dstMat, CV_16SC1, 0, 1, 3);
		imshow("frame", frame);
		imshow("dstMat", dstMat);
		
		waitKey(30);
	}
}