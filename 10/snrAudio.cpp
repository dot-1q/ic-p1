#include "AudioFile/AudioFile.h"
#include <cmath>
#include <iostream>
#include <ostream>
#include <math.h>

using namespace std;

int main(int argc, char *argcv[])
{
    AudioFile<double> originalFile;
    AudioFile<double> pressedFile;
    double A = 0, error=0, esquared=0;


    originalFile.load("file_example_WAV_1MG.wav");
    pressedFile.load("compressed.wav");


    
    double originalSample = 0;
    double compSample = 0;
    double maxSampleError = 0;
    for (int i=0;i<pressedFile.getNumSamplesPerChannel();i++)
    {
        for(int channel = 0; channel < originalFile.getNumChannels(); channel++)
        {
            originalSample = originalFile.samples[channel][i];       //Aceder a cada sample individualmente
            compSample = pressedFile.samples[channel][i];
            
            if (abs(originalSample) > A) {
                // Calculo o A^2 que é o valor máximo do sinal
                A = pow(abs(compSample),2) ; 
            }
            // e^2 será igual ao erro^2 da imagem original menos a imagem comprimida 
            error = error + pow((originalSample - compSample), 2);
            // guardar o maior valor absoluto do erro
            if(abs(originalSample - compSample) > maxSampleError) maxSampleError = abs(originalSample-compSample);
        }
    }
    // e^2 é o valor médio, pelo que temos de dividir pelo numero de todas as samples
    esquared = error / (pressedFile.getNumSamplesPerChannel() * pressedFile.getNumChannels()); 
    esquared = pow(esquared,2);
    cout << "SNR: " << 10 * log10(A/esquared) << " dB" << endl;
    cout << "Emax: " << maxSampleError << endl;
    return 0;
}

