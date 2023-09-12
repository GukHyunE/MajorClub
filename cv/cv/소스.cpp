#include <opencv2\opencv.hpp>
#include<stdio.h>
#include<iostream>
#include <opencv2/core/fast_math.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0); // open the default camera

	if (!cap.isOpened())  // check if we succeeded

		return -1;



	namedWindow("Video", 1);

	namedWindow("Video1", 1);



	while (1) // 무한루프

	{

		Mat frame, gray_frame;

		cap >> frame;         // 카메라로부터 새 프레임을 얻는다. 

		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);    // 얻은 프레임을 그레이이미지로 변환한다. 

		imshow("Video1", frame);    // 컬러영상 전시

		imshow("Video", gray_frame);    // 그레이 영상 전시



		if (waitKey(30) == 'c') break;    // c를 타이핑해줘야 무한루프 탈출! 

	}



	return 0;
	/*while (1) {
	Mat src, src_gray;
	Mat video;
	VideoCapture cap(0);
	
		cap >> src;

		cvtColor(src, src_gray, COLOR_BGR2GRAY);
		threshold(src_gray, src_gray, 50, 255, THRESH_BINARY | THRESH_OTSU);
		GaussianBlur(src_gray, src_gray, Size(5, 5), 2, 2);
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5), Point(-1, -1));
		erode(src_gray, src_gray, element);
		dilate(src_gray, src_gray, element);
		Mat src_gray_blur;
		GaussianBlur(src_gray, src_gray_blur, Size(5, 5), 1);
		addWeighted(src_gray, 2, src_gray_blur, -1, 0, src_gray);
		imshow("camera img", src_gray);
	}
	vector<Vec3f> circles;
	int* x = 0;
	int* y = 0;
	HoughCircles(src_gray, circles, HOUGH_GRADIENT, 1, 100, 40, 37, 10, 200);
	if (circles.size()<4)
		imshow("dst", src);
	else if (circles.size() == 4) {
		cout << " 원 검출" << circles.size() << endl;
		for (size_t i = 0; i < circles.size(); i++) {
			Point center(cvRound(circles[i][2]), cvRound(circles[i][1]));
			x[i] = circles[i][0];
			y[i] = circles[i][1];
			int radius = cvRound(circles[i][2]);
			circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		}
	}
	Mat src_hsv;
	int hue = 0;
	cvtColor(src, src_gray, COLOR_BGR2HSV);
	hue = (int)src_hsv.at<Vec3b>(y[1], x[1])[0] * 2;
	if (hue < 70 || hue > 300)
		cap2 >> video;
	else if (hue >= 70 && hue <= 170)
		cap3 >> video;
	else
		cap4 >> video; //video가 보여주는 mat 변수
	
	Mat white(video.size(), CV_8UC1, Scalar(100));
	vector<Point2f> corners(4);
	corners[0] = Point2f(0, 0);
	corners[1] = Point(0, 0);
	corners[2] = Point(video.cols - 1, 0);
	corners[3] = Point2f(video.cols - 1, video.rows - 1);
	

	for (int i = 0; i < 3; i++) {
		int min = x[i];
		int idx = i;
		for (int j = i + 1; j < 4; j++) {
			if (min > x[j]) {
			min = x[j];
				idx = j;
			}
		}
		if (idx != i) {
			int tmpx = x[i];
			x[i] = x[idx];
			x[idx] = tmpx;

			int tmpy = y[i];
			y[i] = y[idx];
			y[idx] = tmpy; 
	}
	}
	

	vector<Point2f>warpCorners(4);
	Mat warpImg(src.size(), src.type());
	if (y[0] < y[1]) {
		warpCorners[0] = Point2f(x[0], y[0]);
		warpCorners[2] = Point2f(x[1], y[1]);
	}
	else {
		warpCorners[0] = Point2f(x[1], y[1]);
		warpCorners[2] = Point2f(x[0], y[0]);
	}

	if (y[2] < y[3]) {
		warpCorners[1] = Point2f(x[2], y[2]);
		warpCorners[3] = Point2f(x[3], y[3]);
	}
	else {
		warpCorners[1] = Point2f(x[3], y[3]);
		warpCorners[3] = Point2f(x[2], y[2]);
	}
	Mat trans = getPerspectiveTransform(corners, warpCorners);
	warpPerspective(video, warpImg, trans, src.size());
	warpPerspective(white, white, trans, src.size());
	warpImg.copyTo(src, white);
	imshow("dst", src);*/
}




