//#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include <string>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	//leggere immagine da webcam
	cvNamedWindow("Finestra", CV_WINDOW_AUTOSIZE);
	CvCapture* capture;
	if (argc == 1) {
		capture = cvCreateCameraCapture(0);
	}
	else {
		capture = cvCreateFileCapture(argv[1]);
	}
	assert(capture != NULL);
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		cvShowImage("Finestra", frame);
		char c = cvWaitKey(10);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Finestra");
	return 1;
}