#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>


int main(int argc, char *argcv[])
{

    std::ifstream ifs(argcv[1]);
    std::ofstream ofs(argcv[2]);
    char character;

    while(ifs.get(character))
    {
        ofs << character;
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
