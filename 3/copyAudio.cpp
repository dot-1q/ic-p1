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
    cout <<"Numero de samples " << newFile.getNumSamplesPerChannel() << endl;

    
    for (int i=0;i<newFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < audioFile.getNumChannels(); channel++)
        {
            double currentSample = audioFile.samples[channel][i];
            // Copiar para o novo ficheiro a sample isolada
            newFile.samples[channel][i] = currentSample;
        }
    }

    // Novo ficheiro terá de ter o mesmo sample rate, para que a duração do mesmo seja igual ao original
    newFile.setSampleRate(audioFile.getSampleRate()); 
    newFile.save(argcv[2],AudioFileFormat::Wave);
    return 0;
}

