#include<iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	double scale = 0.5;

	double i_minH = 0;
	double i_maxH = 20;
	double i_minS = 43;
	double i_maxS = 255;
	double i_minV = 55;
	double i_maxV = 255;

	while (1) {
		Mat frame,hsvMat,detectMat,medMat, dipMat;
		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV),detectMat);

		cv::GaussianBlur(rFrame, medMat, cv::Size(5, 5), 3, 3);

		rFrame.copyTo(dipMat);
		medMat.copyTo(dipMat, detectMat);
		imshow("whie:in the range", detectMat);
		imshow("display", dipMat);
		imshow("frame", rFrame);
		waitKey(30);


	}
}


