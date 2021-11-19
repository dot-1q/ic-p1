#include <cmath>
#include <opencv4/opencv2/core/hal/interface.h>
#include <opencv4/opencv2/core/matx.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <ostream>

using namespace cv;

int main(int argc, char *argcv[]){ 

    Mat inputFile = imread("airplane.ppm");
    Mat greyScale;
    std::ofstream redFile ("red.txt");
    std::ofstream greenFile ("green.txt");
    std::ofstream blueFile ("blue.txt");
    std::ofstream greyscaleFile ("greyscale.txt");
    // array que vai conter o numero de vezes que determinado byte ocorre | Array iniciado com as ocorrencias a zero
    int byteArray[256] = { };

    std::cout << "BEGINING COLOR CHANNELS ..." << std::endl;
    // Variable to store the byte from each channel
    int byteFromPixel;
    // Get all the bytes from the red channel 
    for(int channel=0; channel< inputFile.channels();channel++)
    {
        for (int i = 0; i < inputFile.rows; i++)
        {
            for(int j = 0; j<inputFile.cols;j++)
            {
                // Store the byte in each corresponding file according to channel
                byteFromPixel = inputFile.at<Vec3b>(i,j)[channel];
                byteArray[byteFromPixel]++;
                if(channel==0) redFile << byteFromPixel <<std::endl; 
                if(channel==1) greenFile << byteFromPixel <<std::endl; 
                if(channel==2) blueFile << byteFromPixel <<std::endl; 
            }
        }
    }
    redFile.close();
    greenFile.close();
    blueFile.close();
    std::cout << "COLOR CHANNELS DONE!" << std::endl;
    

    std::cout << "Calculating Entropy" << std::endl;
    float entropy = 0;
    float p = 0;
    float sizeInBytes = inputFile.total() * inputFile.elemSize();
    for(int k = 0; k<256;k++)
    {
        if(byteArray[k] > 0)
        {
            // Entropy Formula
            p = byteArray[k] / sizeInBytes;
            entropy = entropy - (p*(log(p)/log(256)));
        }
    }
    std::cout << "Colored Image Entropy: " << (entropy) << std::endl;

    // GREY SCALE IMAGE //

    std::cout << "BEGINING GREYSCALE IMAGE ..." << std::endl;
    cvtColor(inputFile, greyScale, COLOR_RGB2GRAY);
    imwrite("greyscale.jpg", greyScale);

    int byteArrayGS[256] = { };
    // Get all the bytes from the greyscale image 
    for (int i = 0; i < greyScale.rows; i++)
    {
        for(int j = 0; j<greyScale.cols;j++)
        {
            // Entropy Formula
            byteFromPixel = greyScale.at<uchar>(i,j);
            byteArrayGS[byteFromPixel]++;
            greyscaleFile << byteFromPixel <<std::endl; 
        }
    }
    std::cout << "GREYSCALE IMAGE DONE" << std::endl;
    
    std::cout << "Calculating GreyScale Entropy" << std::endl;
    sizeInBytes = greyScale.total() * greyScale.elemSize();
    entropy = 0;
    p = 0;
    for(int k = 0; k<256;k++)
    {
        if(byteArrayGS[k] > 0)
        {
            p = byteArrayGS[k] / sizeInBytes;
            entropy = entropy - (p*(log(p)/log(256)));
        }
    }
    std::cout << "Greyscale Image Entropy: " << (entropy) << std::endl;
} 
