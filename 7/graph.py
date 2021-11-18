import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FormatStrFormatter
import pandas as pd
import math
from matplotlib.ticker import StrMethodFormatter

def main():
    # Abre o ficheiro com os dados
    f = open("red.txt", "r")

    # Armazena todos os chars numa lista
    chars = []
    for line in f:
        chars.append(int(line.rstrip()))
	
    # Desenha o histograma com a frequência de cada char
    plt.hist(chars,bins=256)
    plt.xlabel('Characters')
    plt.xticks([0,25,50,75,100,125,150,175,200,225,250])
    plt.ylabel('Frequency')
    plt.title('Red Channel Image Bytes Frequency Histogram')
    plt.savefig('RedChannelBytetHist.png',bbox_inches="tight")
    plt.close()
    
    
    # Abre o ficheiro com os dados
    f = open("green.txt", "r")

    # Armazena todos os chars numa lista
    chars = []
    for line in f:
        chars.append(int(line.rstrip()))
	
    # Desenha o histograma com a frequência de cada char
    plt.hist(chars,bins=256)
    plt.xlabel('Characters')
    plt.xticks([0,25,50,75,100,125,150,175,200,225,250])
    plt.ylabel('Frequency')
    plt.title('Green Channel Image Bytes Frequency Histogram')
    plt.savefig('GreenChannelBytetHist.png',bbox_inches="tight")
    plt.close()
    
    
        # Abre o ficheiro com os dados
    f = open("blue.txt", "r")

    # Armazena todos os chars numa lista
    chars = []
    for line in f:
        chars.append(int(line.rstrip()))
	
    # Desenha o histograma com a frequência de cada char
    plt.hist(chars,bins=256)
    plt.xlabel('Characters')
    plt.xticks([0,25,50,75,100,125,150,175,200,225,250])
    plt.ylabel('Frequency')
    plt.title('Blue Channel Image Bytes Frequency Histogram')
    plt.savefig('BlueChannelBytetHist.png',bbox_inches="tight")
    plt.close()
    
            # Abre o ficheiro com os dados
    f = open("greyscale.txt", "r")

    # Armazena todos os chars numa lista
    chars = []
    for line in f:
        chars.append(int(line.rstrip()))
	
    # Desenha o histograma com a frequência de cada char
    plt.hist(chars,bins=256)
    plt.xlabel('Characters')
    plt.xticks([0,25,50,75,100,125,150,175,200,225,250])
    plt.ylabel('Frequency')
    plt.title('Greyscale Image Bytes Frequency Histogram')
    plt.savefig('GreyscaleChannelBytetHist.png',bbox_inches="tight")
    plt.close()
    
if __name__== "__main__":
    main()
