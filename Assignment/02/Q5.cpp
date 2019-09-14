#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
	// VideoCapture cap(0);
	VideoCapture cap("video_test.mp4");
	if (!cap.isOpened())
	{
		cout << "Cannot open" << endl;
	}
	Mat Frame, reFrame, reFrame_g; // �������� ���� ��ü�� ������ �������� �������� ���� ��ü ����
	namedWindow("Frame", 1);
	for (;;)
	{
		cap >> Frame;
		resize(Frame, reFrame, Size(640, 360), 0, 0, INTER_AREA); // ����� ����
		cvtColor(reFrame, reFrame_g, COLOR_RGB2GRAY);
		imshow("ReFrame", reFrame_g);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}
