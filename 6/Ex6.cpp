#include "AudioFile/AudioFile.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argcv[]){   
    AudioFile<double> audioFile;
    ofstream leftFile ("left.txt");
    ofstream rightFile ("right.txt");
    ofstream monoFile ("mono.txt");

    // Load the Audio File
    audioFile.load ("file_example.wav");

    // Number os samples per channel
    int numSamples = audioFile.getNumSamplesPerChannel();
    cout << numSamples << endl;
    
    cout << "BEGINING STEREO AUDIO..." << endl;
    // Iterate over the number of channels
    // Save the data to a file named "data.txt"
    for(int channel = 0; channel < audioFile.getNumChannels(); channel++){
        // Get all the samples from the specific sample
        for (int i = 0; i < audioFile.getNumSamplesPerChannel(); i++){
            double currentSample = audioFile.samples[channel][i];

            if(channel == 0){
                leftFile << currentSample << endl;
            }
            else{
                rightFile << currentSample << endl;
            }
        }
    }
    cout << "STEREO AUDIO DONE!" << endl;

    cout << "BEGINING MONO AUDIO..." << endl;
    for(int sample = 0; sample < audioFile.getNumSamplesPerChannel(); sample++){
        double left = 0, right = 0;

        for(int ch = 0; ch < audioFile.getNumChannels(); ch++){
            if (ch == 0){
                left = audioFile.samples[ch][sample]; 
            }
            else{
                right = audioFile.samples[ch][sample]; 
            }
        }
        double monoSample = (left + right) / 2;
        monoFile << monoSample << endl;

        left = 0;
        right = 0;  
    }
    cout << "MONO AUDIO DONE!" << endl;
}