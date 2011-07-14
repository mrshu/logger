#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "base64.h"

IplImage *img, *imgThreshed; 

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
	
	CvCapture* camera = cvCaptureFromCAM(0);
	cvSetCaptureProperty( camera, CV_CAP_PROP_FRAME_WIDTH, 160);
	cvSetCaptureProperty( camera, CV_CAP_PROP_FRAME_HEIGHT, 120);

	vector<uchar> buff;

	while(1) {
		img = cvQueryFrame(camera);
		if (img == NULL)
			continue;
		
		char c;
		cin >> c;
		
		vector<int> param = vector<int>(2);
        	param[0] = CV_IMWRITE_JPEG_QUALITY;
        	param[1] = 95;

		imencode(".jpg", img, buff, param);		

		string out = base64_encode(&buff[0], buff.size());

		printf("%d\n", buff.size());
		cout <<  out << endl;
		buff.clear();
		cvWaitKey(1000);
	}


}

