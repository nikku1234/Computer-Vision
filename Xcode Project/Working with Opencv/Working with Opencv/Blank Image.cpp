//
//  Blank Image.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 27/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "Blank Image.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
 //create a new image which consists of
 //3 channels
 //image depth of 8 bits
 //800 x 600 of resolution (800 wide and 600 high)
 //each pixels initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectively.
 Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));
 
 String windowName = "Window with Blank Image"; //Name of the window

 namedWindow(windowName); // Create a window

 imshow(windowName, image); // Show our image inside the created window.

 waitKey(0); // Wait for any keystroke in the window

 destroyWindow(windowName); //destroy the created window

 return 0;
}
