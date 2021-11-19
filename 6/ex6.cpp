#include "AudioFile/AudioFile.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <math.h>

using namespace std;

int main(int argc, char *argcv[]){   
    AudioFile<double> audioFile;
    ofstream leftFile ("left.txt");
    ofstream rightFile ("right.txt");
    ofstream monoFile ("mono.txt");
    
    // Hashmap of the samples frequency and the number of times they occur 
    map<double, int> freqMap;
    map<double, int> leftFreqMap;
    map<double, int> rightFreqMap;
    map<double, int> monoFreqMap;
    
    // Load the Audio File
    audioFile.load ("file_example.wav");
    
    cout << "BEGINING STEREO AUDIO..." << endl;
    // Iterate over the number of channels
    // Save the data to a file named "data.txt"
    double currentSample;
    double roundedSample;
    for(int channel = 0; channel < audioFile.getNumChannels(); channel++){
        // Get all the samples from the specific sample
        for (int i = 0; i < audioFile.getNumSamplesPerChannel(); i++){
            currentSample = audioFile.samples[channel][i];
            roundedSample = round(currentSample*100.0) / 100.0;   // Round the sample value to 3 decimal places 

            // Insert into hashmap the sample, and the number of times it has occured
            if(freqMap.count(roundedSample))
            {
                freqMap[roundedSample] = freqMap[roundedSample] +1;
            }else {
                freqMap[roundedSample] = 1;
            }

            // Insert into hashmap the sample, and the number of times it has occured
            if(channel == 0){
                if(leftFreqMap.count(roundedSample))
                {
                    leftFreqMap[roundedSample] = leftFreqMap[roundedSample] +1;
                }else {
                    leftFreqMap[roundedSample] = 1;
                }
            }
            else{
                if(rightFreqMap.count(roundedSample))
                {
                    rightFreqMap[roundedSample] = rightFreqMap[roundedSample] +1;
                }else {
                    rightFreqMap[roundedSample] = 1;
                }
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
        // Mono audio should be the median of both channels
        double monoSample = (left + right) / 2;
        roundedSample = round(monoSample*100.0) / 100.0;   // Round the sample value to 3 decimal places 
        // Insert the mono frequencies into their hashmap
        if(monoFreqMap.count(roundedSample))
        {
            monoFreqMap[roundedSample] = monoFreqMap[roundedSample] +1;
        }else {
            monoFreqMap[roundedSample] = 1;
        }
        left = 0;
        right = 0;  
    }
    cout << "MONO AUDIO DONE!" << endl;

    cout << "Calculating Entropy of the audio file" << endl;
    map<double, int>:: iterator itr;
    float entropy = 0;
    float p = 0;
    float numberOfelements = freqMap.size();
    for (itr = freqMap.begin(); itr != freqMap.end(); itr++)
    {
        // Calculating the entropy
        p = itr->second / numberOfelements;
        entropy = entropy - (p*(log(p)/log(2)));
    }
    cout << "Entropy of audio file: " << abs(entropy)/100000 << endl;

    
    cout << "Creating data files for left,right and mono channels samples frequency" << endl;
    for (itr = leftFreqMap.begin(); itr != leftFreqMap.end(); itr++)
    {
        // Calculating the entropy
        leftFile << itr->first << ',' << itr->second << endl;
    }

    for (itr = rightFreqMap.begin(); itr != rightFreqMap.end(); itr++)
    {
        // Calculating the entropy
        rightFile << itr->first << ',' << itr->second << endl;
    }

    for (itr = monoFreqMap.begin(); itr != monoFreqMap.end(); itr++)
    {
        // Calculating the entropy
        monoFile << itr->first << ',' << itr->second << endl;
    }
    leftFile.close();
    rightFile.close();
    monoFile.close();
}
