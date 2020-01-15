##### The project is built with Ubuntu 18.04.3 LTS and CMake version 3.10.2

The "CMakeLists.txt" file has already the OpenCV libraries included for Linux directories. "CMakeLists.txt" libraries directories have to be changed for windows or any other operating system.

I have added some screenshots to demonstrate the program in working condition with different image input.


![2](https://user-images.githubusercontent.com/55370357/72447378-86e53d00-37b5-11ea-9fe9-0b3366999370.png)

We have already built the program using CMake, this step varies between platform to platform, that's why we are not describing in detail about the process.
In the main() class we have given the input path of the image "data/Image_3.png". The next step is to make, we have done it simply running make in the program directory. Now we have an executable file "edge_detection_bin" which when we run it using "./edge_detection_bin" from our terminal. The final result is image with edges detected.


![3](https://user-images.githubusercontent.com/55370357/72447387-89e02d80-37b5-11ea-825e-184b6073c3b5.png)

In the second screenshot, we have only changed the image name from "data/Image_3.png" to "data/Image_5.jpg" and we also have the expected output.
