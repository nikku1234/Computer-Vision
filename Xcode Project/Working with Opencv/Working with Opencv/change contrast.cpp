//
//  change contrast.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 29/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "change contrast.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("original.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    Mat imageContrastHigh2;
    image.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

    Mat imageContrastHigh4;
    image.convertTo(imageContrastHigh4, -1, 4, 0); //increase the contrast by 4

    Mat imageContrastLow0_5;
    image.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

    Mat imageContrastLow0_25;
    image.convertTo(imageContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25


    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    //Show above images inside the created windows.
    imshow(windowNameOriginalImage, image);
    imshow(windowNameContrastHigh2, imageContrastHigh2);
    imshow(windowNameContrastHigh4, imageContrastHigh4);
    imshow(windowNameContrastLow0_5, imageContrastLow0_5);
    imshow(windowNameContrastLow0_25, imageContrastLow0_25);
    
    imwrite("contrast/imageContrastHigh2.jpg", imageContrastHigh2);
    imwrite("contrast/imageContrastHigh4.jpg", imageContrastHigh4);
    imwrite("contrast/imageContrastLow0_5.jpg", imageContrastLow0_5);
    imwrite("contrast/imageContrastLow0_25.jpg", imageContrastLow0_25);

    waitKey(0); // Wait for any key stroke

    destroyAllWindows(); //destroy all open windows

    return 0;
}
