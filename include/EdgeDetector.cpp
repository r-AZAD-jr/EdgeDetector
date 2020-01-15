#include "EdgeDetector.hpp"
using namespace edge_detection;

cv::Mat EdgeDetector::getInputImage(char *inputImagePath)
{
	// This function will return the image in cv::Mat format.
	// We kept the default BGR format.
	return cv::imread(inputImagePath);
}

void EdgeDetector::showImage(cv::Mat *outputImage)
{
	// "showImage" function will simply show the processed image.

	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	cv::imshow(window_name, *outputImage);

	// We will wait for a keystroke by the user so that we can observe the GUI output of the processed image.
	cv::waitKey(0);
}

cv::Mat* EdgeDetector::applyingCannyEdgeDetector(
		cv::Mat imageNeedsToBeProcessed)
{
	// This function is applying the Canny Edge Detector. We will go through this function line by line.

	// First, we are converting color BGR to Gray.(Because of "Image_5.jpg")
	cv::cvtColor(imageNeedsToBeProcessed, imageNeedsToBeProcessed,
			cv::COLOR_BGR2GRAY);

	// Secondly, we are applying the Gausian filter to remove any noise from it.
	// (Because of "Image_2.png")
	cv::blur(imageNeedsToBeProcessed, imageNeedsToBeProcessed, cv::Size(3, 3));

	/* Finally, we are calling cv::Canny which gives us the detected edges.
	 We have seen before the Hysteresis Thresholding and we have kept the "lowThreshold" as it is
	 and changed the second threshold to "lowThreshold * ratio" multiplication with ratio.
	 And we kept the kernel size to 3.*/
	cv::Canny(imageNeedsToBeProcessed, imageNeedsToBeProcessed, lowThreshold,
			lowThreshold * ratio, kernel_size);

	// In the end, we have saved the processed image to "edgeDetectedImage"
	// to increase the scope of the processed data.
	edgeDetectedImage = imageNeedsToBeProcessed;
	return &edgeDetectedImage;
}

cv::Mat* EdgeDetector::colorChangeAndSuperimposed(cv::Mat *detectedEdge,
		cv::Mat *originalImage)
{
	// This function will change the detected pixels into green and superimpose them with the original picture.

	/*We have declared two local variables of cv::Mat because later in
	 the road we will need to use ".at<cv::Vec3d>(,)".
	 We were also trying to keep the scope of the variables local,
	 which will help in case of debugging purposes.*/
	cv::Mat detectedEdgeBGR;
	cv::Mat localOriginalImage = *originalImage;

	// We are converting our detected edges back into BGR because our original image is in BGR.
	cv::cvtColor(*detectedEdge, detectedEdgeBGR, cv::COLOR_GRAY2BGR);

	/* In the loop, we are looking for white pixels in the edge detected image
	 and converting the corresponding pixels of the original image to green. */
	for (int y = 0; y < detectedEdgeBGR.rows; y++)
	{
		for (int x = 0; x < detectedEdgeBGR.cols; x++)
		{
			cv::Vec3b &detectedImagePixel = detectedEdgeBGR.at<cv::Vec3b>(y, x);
			cv::Vec3b &originalImagePixel = localOriginalImage.at<cv::Vec3b>(y,
					x);

			if (detectedImagePixel[0] == 255 || detectedImagePixel[1] == 255
					|| detectedImagePixel[3] == 255)
			{
				originalImagePixel[0] = 0;
				originalImagePixel[1] = 255;
				originalImagePixel[2] = 0;
			}
		}
	}

	/* Finally, we have the edge detected superimposed image and
	 we are replacing the original image with the new one.*/
	*originalImage = localOriginalImage;
	return originalImage;
}
