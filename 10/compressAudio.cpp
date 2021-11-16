#include "AudioFile/AudioFile.h"
#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

int main(int argc, char *argcv[])
{
    AudioFile<double> originalFile;
    AudioFile<double> pressedFile;
    double Ex = 0, Er=0;


    originalFile.load("file_example_WAV_1MG.wav");
    pressedFile.load("compressed.wav");


    
    for (int i=0;i<pressedFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < originalFile.getNumChannels(); channel++)
        {
            double originalSample = originalFile.samples[channel][i];       //Aceder a cada sample individuamente
            double compSample = pressedFile.samples[channel][i];
            // elevar ao quadrado e somar
            Ex = Ex + pow(originalSample,2);
            Er = Er + pow((originalSample - compSample), 2);
        }
    }
    
    
    cout << "SNR: " << 10 * log10(Ex/Er) <<endl;
    return 0;
}

