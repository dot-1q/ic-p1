#include <opencv2/core/hal/interface.h>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argcv[])
{

    Mat input = imread(argcv[1]);
    Mat output = Mat::zeros(Size(input.rows,input.cols),input.type());
    std::cout<<"type "<<input.type()<<" depth "<<input.depth()<<" channels "<<input.channels()<<"\n";// type 16 depth 0 channels 3

   for(int i=0;i<input.rows;i++)
    {
        for(int j = 0;j<input.cols;j++)
       {
           // Shift right 1 bit on each byte of the pixel
            output.at<Vec3b>(i,j)[0] = input.at<Vec3b>(i,j)[0]>>1;
            output.at<Vec3b>(i,j)[1] = input.at<Vec3b>(i,j)[1]>>1;
            output.at<Vec3b>(i,j)[2] = input.at<Vec3b>(i,j)[2]>>1;
        }
    }
   
    imwrite(argcv[2],output);
    return 0;
}
