#include "AudioFile/AudioFile.h"
#include <iostream>
#include <ostream>

using namespace std;

int main(int argc, char *argcv[])
{
    AudioFile<double> audioFile;
    AudioFile<double> newFile;
    double soma = 0;


    audioFile.load("file_example_WAV_1MG.wav");

    newFile.setNumChannels(audioFile.getNumChannels());
    //ciar novo ficheiro como o mesmo numero de samples
    newFile.setNumSamplesPerChannel(audioFile.getNumSamplesPerChannel());
    cout <<"Numero de samples " << audioFile.getNumSamplesPerChannel() << endl;
    cout <<"Bit Depth " << audioFile.getBitDepth() << endl;

    
    for (int i=0;i<newFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < audioFile.getNumChannels(); channel++)
        {
            double currentSample = audioFile.samples[channel][i];       //Aceder a cada sample individuamente
            // elevar ao quadrado e somar
            soma = soma + (currentSample * currentSample);
        }
    }
    newFile.setSampleRate(audioFile.getSampleRate()); 
    newFile.save(argcv[2],AudioFileFormat::Wave);

    // Comparar samples de ambos os ficheiros
    for (int i=0;i<newFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < audioFile.getNumChannels(); channel++)
        {
            double sampleOriginal = audioFile.samples[channel][i];
            double sampleFinal = newFile.samples[channel][i];
            cout << "Sample original: " << sampleOriginal << endl;
            cout << "Sample final: " << sampleFinal << endl;
            cout << "Diferença Percentual: " << ((sampleOriginal-sampleFinal)/sampleOriginal)*100 << "%" << endl;
        }
    }
    return 0;
}

