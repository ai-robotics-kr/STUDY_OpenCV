#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
int drawingL = false;
int drawingR = false;

void draw(int event, int x, int y, int, void* param)
{
	if (event == EVENT_LBUTTONDOWN) 
		drawingL = true; 
	else if (event == EVENT_MOUSEMOVE)
	{
		if (drawingL == true) 
		{
			circle(img, Point(x, y), 100, Scalar(0, 0, 255), 3); // Scalar : R, G, B 값을 저장하는 객체를 생성함
		}
	}
	else if (event == EVENT_LBUTTONUP) // 마우스에서 손을 땟을때
		drawingL = false; // 클릭 해제
	if (event == EVENT_RBUTTONDOWN)
		drawingR = true;
	else if (event == EVENT_MOUSEMOVE)
	{
		if (drawingR == true)
		{
			rectangle(img, Point(x, y), Point(x + 100, y + 100), Scalar(255, 0, 0), 2);
		}
	}
	else if (event == EVENT_RBUTTONUP) // 마우스에서 손을 땟을때
		drawingR = false; // 클릭 해제

	imshow("Result image", img);
}

int main()
{
	img = Mat::zeros(800, 600, CV_8UC3);
	imshow("original image", img);

	setMouseCallback("original image", draw);
	waitKey(0);

	imwrite("drawing.jpg", img); 
	return 0;
}

