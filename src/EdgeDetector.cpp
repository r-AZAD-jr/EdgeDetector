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

	/*
	 "applyingCannyEdgeDetector" class takes the original image as in input parameters and gives
	 back the address of detected edges in cv::Mat* in Gray Scale.

	 "colorChangeAndSuperimposed" it takes two parameters. The first one is the address of
	 detected edges in the Gray Scale and the second one is the address of the original image.
	 It gives us back an image with edges detected in green color superimposed with the original image.

	 Third class "showImage" is going to show the image and wait for a keystroke form unser
	 and then terminate the GUI with picture.
	 */

	detector.showImage(
			detector.colorChangeAndSuperimposed(
					detector.applyingCannyEdgeDetector(originalInputImage),
					&originalInputImage));

	return 0;
}
