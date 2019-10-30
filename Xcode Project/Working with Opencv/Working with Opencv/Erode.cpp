//
//  Erode.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 30/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "Erode.hpp"
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

    //Erode the image with 3x3 kernel
    Mat image_eroded_with_3x3_kernel;
    erode(image, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(3, 3)));

    //Erode the image with 5x5 kernel
    Mat image_eroded_with_5x5_kernel;
    erode(image, image_eroded_with_5x5_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

    //Define names of the windows
    String window_name = "Nik";
    String window_name_eroded_with_3x3_kernel = "Lotus eroded with 3 x 3 kernel";
    String window_name_eroded_with_5x5_kernel = "Lotus eroded with 5 x 5 kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_eroded_with_3x3_kernel);
    namedWindow(window_name_eroded_with_5x5_kernel);

    // Show our images inside the created windows.
    imshow(window_name, image);
    imshow(window_name_eroded_with_3x3_kernel, image_eroded_with_3x3_kernel);
    imshow(window_name_eroded_with_5x5_kernel, image_eroded_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows

    return 0;
}
