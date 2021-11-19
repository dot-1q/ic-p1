#include <opencv2/core/hal/interface.h>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argcv[])
{

    Mat input = imread(argcv[1]);
    // Criar uma nova matriz inicializada a 0, que irá armazenar os pixeis da imagem original
    Mat output = Mat::zeros(Size(input.rows,input.cols),input.type());
    std::cout<<"type "<<input.type()<<" depth "<<input.depth()<<" channels "<<input.channels()<<"\n";// type 3 depth 3 channels 1

   for(int i=0;i<input.rows;i++)
    {
        for(int j = 0;j<input.cols;j++)
       {
            //Copiar o pixel para o novo ficheiro
            output.at<Vec3b>(i,j) = input.at<Vec3b>(i,j);
        }
    }


    imwrite(argcv[2],output);
    return 0;
}
