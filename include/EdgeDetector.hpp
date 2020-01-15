#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#pragma once

namespace edge_detection
{

class EdgeDetector
{

private:

	// The following constant variables are parameters for the Canny edge detector in OpenCV.

	// Pixels gradient value less then "lowThreshold" is rejected.
	const int lowThreshold = 140;

	/*
	 According to the recommendation of canny the ratio between the lower threshold value and upper
	 threshold value should be between 2:1 and 3:1.
	 In our application, we have selected 3.
	 Reference : https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html
	 */
	const int ratio = 3;

	// Kernel size is defined as 3 for Canny dege detector.
	// We tried different kernel sizes, for our input image size 3 is the optimum one.
	const int kernel_size = 3;

	// We are defining the name of the window, will show the final processed image.
	const char *window_name = "Edge Map";

	/* This variable is to store the detected edges in the image in GrayScale mode.
	 We have used this variable to increase the scope of the detected edged image beyond the local function scope.
	 */
	cv::Mat edgeDetectedImage;

public:

	// We wrote about the description of the function on the EdgeDetector.cpp file.

	cv::Mat getInputImage(char *inputImagePath);
	void showImage(cv::Mat *outputImage);

	cv::Mat* applyingCannyEdgeDetector(cv::Mat imageNeedsToBeProcessed);
	cv::Mat* colorChangeAndSuperimposed(cv::Mat *detectedEdge,
			cv::Mat *originalImage);

};
}
