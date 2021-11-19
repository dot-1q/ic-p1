#include <cmath>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argcv[])
{

    Mat original = imread("airplane.ppm");
    Mat comp = imread("out.ppm");
    double A=0, error=0, esquared=0;

    int originalPixelSum = 0;
    int compPixelSum = 0;
    int maxPixelError = 0;
    for(int i=0;i<original.rows;i++)
    {
        for(int j = 0;j<original.cols;j++)
        {
            // Ambas as imagens tem 3 channels de cor, somamos as 3 e dividimos
            originalPixelSum = (original.at<Vec3b>(i,j)[0] + original.at<Vec3b>(i,j)[1] + original.at<Vec3b>(i,j)[2])/3;
            compPixelSum = (comp.at<Vec3b>(i,j)[0] + comp.at<Vec3b>(i,j)[1] + comp.at<Vec3b>(i,j)[2])/3;
            
            //Obter o valor máximo 
            if(originalPixelSum > A) A = pow(originalPixelSum,2);
            error = error + pow((originalPixelSum-compPixelSum),2);
            
            // Pixel Error
            if((originalPixelSum-compPixelSum) > maxPixelError) maxPixelError = (originalPixelSum-compPixelSum);
        }
    }

    esquared = error/ (original.cols * original.rows * original.channels());
    esquared = pow(esquared,2);
    std::cout << "SNR: " << 10  * log10(A/esquared) << " dB" << std::endl;
    std::cout << "Emax: " << maxPixelError << std::endl;
   
    return 0;
}
