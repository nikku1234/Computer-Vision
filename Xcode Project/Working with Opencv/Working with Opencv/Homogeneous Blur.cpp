//
//  Homogeneous Blur.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 30/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "Homogeneous Blur.hpp"
//Uncomment the following line if you are compiling this code in Visual Studio
//#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("nik.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    //Blur the image with 3x3 kernel
    Mat image_blurred_with_3x3_kernel;
    blur(image, image_blurred_with_3x3_kernel, Size(3, 3));

    //Blur the image with 5x5 kernel
    Mat image_blurred_with_5x5_kernel;
    blur(image, image_blurred_with_5x5_kernel, Size(5, 5));

    //Define names of the windows
    String window_name = "The Nikhil";
    String window_name_blurred_with_3x3_kernel = "The Guitar Blurred with 3 x 3 Kernel";
    String window_name_blurred_with_5x5_kernel = "The Guitar Blurred with 5 x 5 Kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_blurred_with_3x3_kernel);
    namedWindow(window_name_blurred_with_5x5_kernel);

    // Show our images inside the created windows.
    imshow(window_name, image);
    imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows

    return 0;
}
