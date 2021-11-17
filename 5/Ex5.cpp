#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argcv[]){   
    if(argc != 3){
        cout << "ERROR! Usage Ex5.out [input file] [output file]" << endl;
    }
    else{
        // Lê ficheiro de entrada
        ifstream file(argcv[1]);
        // Ficheiro para armazenar os dados para o histograma
        ofstream dataFile (argcv[2]);
        char c;

        while(!file.eof()){
            file >> c;
            dataFile << c << endl;
        }
    }
}