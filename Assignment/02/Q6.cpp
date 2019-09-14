#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
	Mat src, dst;
	src = imread("cat.jpg", IMREAD_COLOR);
	imshow("original img", src);

	flip(src, dst, 1);
	imshow("flipped img", dst);
	imwrite("img_flip.jpg", dst);
	waitKey(0);
	return 0;
}
