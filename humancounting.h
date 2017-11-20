#pragma once
#include <cstdlib>
#include <opencv\cv.h>
#include <opencv2\highgui.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\imgproc.hpp>

using namespace System;

//class Counter {
//public:
//	static int iNum;
//	static const char* iImgPath;
//	static IplImage* iImg;
//
//	static void num_human();
//};

extern int iNum;
extern const char* iImgPath;
extern IplImage* iImg;

extern void num_human();