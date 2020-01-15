# The project Canny Edge Detector is built with Ubuntu 18.04.3 LTS and CMake version 3.10.2 with C++

The "CMakeLists.txt" file has already OpenCV libraries included for Linux directories. "CMakeLists.txt" library directories have to be changed for windows or any other operating system. We have already built the program using CMake, this step varies between platform to platform, that's why we are not describing in detail about the process.

Detailed implementation of the program is commented on in the actual source file of the program.

I have added some screenshots to demonstrate the program in working conditions with different input images.


![2](https://user-images.githubusercontent.com/55370357/72447378-86e53d00-37b5-11ea-9fe9-0b3366999370.png)

In the main() class we have given the path of the image we want to detect edges "data/Image_3.png". The next step is to make the program, we have done it simply running "make" in the Linux terminal. Now we have an executable file "edge_detection_bin" which we can run using "./edge_detection_bin" from the terminal. The final result is an image with edges detected.


![3](https://user-images.githubusercontent.com/55370357/72447387-89e02d80-37b5-11ea-825e-184b6073c3b5.png)

In the second screenshot, we have only changed the image name from "data/Image_3.png" to "data/Image_5.jpg" and rebuilt and execute the program again with "make && ./edge_detection_bin". As we can see above the output is an image with edge detected in green.
