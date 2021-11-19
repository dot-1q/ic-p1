#include "AudioFile/AudioFile.h"
#include <iostream>
#include <ostream>

using namespace std;

int main(int argc, char *argcv[])
{
    AudioFile<double> audioFile;
    AudioFile<double> newFile;


    audioFile.load(argcv[1]);

    newFile.setNumChannels(audioFile.getNumChannels());
    //ciar novo ficheiro como o mesmo numero de samples
    newFile.setNumSamplesPerChannel(audioFile.getNumSamplesPerChannel());
    cout <<"Numero de samples " << audioFile.getNumSamplesPerChannel() << endl;
    cout <<"Bit Depth " << audioFile.getBitDepth() << endl;

    
    for (int i=0;i<newFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < audioFile.getNumChannels(); channel++)
        {
            double currentSample = audioFile.samples[channel][i];
            // descartar 70% dos bits da sample original, multiplicando por 0.3
            newFile.samples[channel][i] = currentSample * 0.3f;
        }
    }
    newFile.setSampleRate(audioFile.getSampleRate()); 
    newFile.save(argcv[2],AudioFileFormat::Wave);

    return 0;
}

