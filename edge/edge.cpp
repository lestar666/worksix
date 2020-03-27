#include<iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	
	while (1) {
		Mat frame;
		cap >> frame;
		Mat grad_x,grad_y;

		Sobel(frame,grad_x, CV_16SC1, 1, 0, 3);
		convertScaleAbs(grad_x, grad_x);

		Sobel(frame, grad_y, CV_16SC1, 0, 1, 3);
		convertScaleAbs(grad_y, grad_y);
		imshow("frame", frame);
		imshow("dstMat1", grad_x);
		imshow("dstMat2", grad_y);

		
		waitKey(30);
	}
}