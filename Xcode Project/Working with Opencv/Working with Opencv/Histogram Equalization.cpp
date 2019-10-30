//
//  Histogram Equalization.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 30/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "Histogram Equalization.hpp"
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat image = imread("original.jpg");
    
    if (image.empty())
    {
        cout<<"Could not open the image"<<endl;
        cin.get();
        return -1;
    }
    //change the color image to grayscale image
    cvtColor(image, image, COLOR_BGR2GRAY);
    
    //equalize the histogram
    Mat hist_equalized_image;
    equalizeHist(image, hist_equalized_image);
    
    //Define the windows
    String windowNameOfOriginalImage = "Original Image";
    String windowNameOfHistogramEqualized = "Histogram Equalized Image";
    
    // Create windows with the above names
    namedWindow(windowNameOfOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameOfHistogramEqualized, WINDOW_NORMAL);

    // Show images inside created windows.
    imshow(windowNameOfOriginalImage, image);
    imshow(windowNameOfHistogramEqualized, hist_equalized_image);

    waitKey(0); // Wait for any keystroke in one of the windows

    destroyAllWindows(); //Destroy all open windows

    return 0;
    
}
