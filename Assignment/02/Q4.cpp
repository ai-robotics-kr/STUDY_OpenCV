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
			circle(img, Point(x, y), 100, Scalar(0, 0, 255), 3); // Scalar : R, G, B ���� �����ϴ� ��ü�� ������
		}
	}
	else if (event == EVENT_LBUTTONUP) // ���콺���� ���� ������
		drawingL = false; // Ŭ�� ����
	if (event == EVENT_RBUTTONDOWN)
		drawingR = true;
	else if (event == EVENT_MOUSEMOVE)
	{
		if (drawingR == true)
		{
			rectangle(img, Point(x, y), Point(x + 100, y + 100), Scalar(255, 0, 0), 2);
		}
	}
	else if (event == EVENT_RBUTTONUP) // ���콺���� ���� ������
		drawingR = false; // Ŭ�� ����

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

