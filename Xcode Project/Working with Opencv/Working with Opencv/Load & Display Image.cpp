//
//  Load & Display Image.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 27/10/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

#include "Load & Display Image.hpp"
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat img = imread("lena.png");
    namedWindow("image", WINDOW_NORMAL);
    imshow("image", img);
    waitKey(0);
    return 0;
}

