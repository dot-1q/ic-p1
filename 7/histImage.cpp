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

    // Load the Image File

    std::cout << "BEGINING COLOR CHANNELS ..." << std::endl;
    // Variable to store the byte from each channel
    double byteFromPixel;

    // Get all the bytes from the red channel 
    for (int i = 0; i < inputFile.rows; i++)
    {
        for(int j = 0; j<inputFile.cols;j++)
        {
            byteFromPixel = inputFile.at<Vec3b>(i,j)[0];
            redFile << byteFromPixel <<std::endl; 
        }
    }

    // Get all the bytes from the green channel 
    for (int i = 0; i < inputFile.rows; i++)
    {
        for(int j = 0; j<inputFile.cols;j++)
        {
            byteFromPixel = inputFile.at<Vec3b>(i,j)[1];
            greenFile << byteFromPixel <<std::endl; 
        }
    }

    // Get all the bytes from the blue channel 
    for (int i = 0; i < inputFile.rows; i++)
    {
        for(int j = 0; j<inputFile.cols;j++)
        {
            byteFromPixel = inputFile.at<Vec3b>(i,j)[2];
            blueFile << byteFromPixel <<std::endl; 
        }
    }
    
    redFile.close();
    greenFile.close();
    blueFile.close();
    std::cout << "COLOR CHANNELS DONE!" << std::endl;

    std::cout << "BEGINING GREYSCALE IMAGE ..." << std::endl;
    cvtColor(inputFile, greyScale, COLOR_RGB2GRAY);
    imwrite("greyscale.jpg", greyScale);
    std::cout << "GREYSCALE IMAGE DONE" << std::endl;
} 
