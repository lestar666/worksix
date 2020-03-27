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
		blur(frame, dstMat, Size(3,3));
		imshow("frame", frame);
		imshow("dstMat", dstMat);
		waitKey(30);
	}
}