//
//  dilate.cpp
//  Working with Opencv
//
//  Created by Nikhil Ramesh on 13/11/19.
//  Copyright © 2019 Nikhil Ramesh. All rights reserved.
//

//#include "dilate.hpp"
#include "stdafx.h"
#include <cv.h>
#include <highgui.h>

int main()
{
        //display the original image
        IplImage* img = cvLoadImage("original.jpg");
        cvNamedWindow("MyWindow");
        cvShowImage("MyWindow", img);

        //dilate and display the dilated image
        cvDilate(img, img, 0, 2);
        cvNamedWindow("Dilated");
        cvShowImage("Dilated", img);

        cvWaitKey(0);
       
        //cleaning up
        cvDestroyWindow("MyWindow");
        cvDestroyWindow("Dilated");
        cvReleaseImage(&img);
       
        return 0;
}
