#include "../include/EdgeDetector.hpp"
#include "../include/EdgeDetector.cpp"

int main()
{
	edge_detection::EdgeDetector detector;

	/*
	 We are calling getInputImage function in EdgeDetector class.
	 getInputImage takes the image path as input and returns back the image
	 as cv::Mat format.
	 */

	// We can simply change the name of the image and it will give us the corresponding output.
	cv::Mat originalInputImage = detector.getInputImage("data/Image_4.png");

	/*
     	We are calling the functions of EdgeDetector to get the final image
     	superimposed with edge detected in green color on the original image.
     	We will find more detail about the functions inside the EdgeDetector class definition.
	 */

	detector.showImage(
			detector.colorChangeAndSuperimposed(
					detector.applyingCannyEdgeDetector(originalInputImage),
					&originalInputImage));

	return 0;
}
