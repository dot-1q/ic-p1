import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FormatStrFormatter
import pandas as pd
import math
from matplotlib.ticker import StrMethodFormatter

def main():
    #LEFT CHANNEL
    data = pd.read_csv('left.txt', sep=',',header=None, index_col =0)

    data.plot(kind='bar')
    plt.ylabel('Number of Frequencies')
    #plt.xticks(np.arange(-0.9, 0.9, 0.1))
    plt.gca().set_xticks(plt.gca().get_xticks()[::10])
    plt.xlabel('Frequency')
    plt.title('Left Channel Histogram')

    
    plt.savefig('leftHist.png',bbox_inches="tight")
    
    
    
    
    # RIGHT CHANNEL
    data = pd.read_csv('right.txt', sep=',',header=None, index_col =0)

    data.plot(kind='bar')
    plt.ylabel('Number of Frequencies')
    #plt.xticks(np.arange(-0.9, 0.9, 0.1))
    plt.gca().set_xticks(plt.gca().get_xticks()[::10])
    plt.xlabel('Frequency')
    plt.title('Right Channel Histogram')

    
    plt.savefig('rightHist.png',bbox_inches="tight")
    
    
    
    # MONO CHANNEl
    data = pd.read_csv('mono.txt', sep=',',header=None, index_col =0)

    data.plot(kind='bar')
    plt.ylabel('Number of Frequencies')
    #plt.xticks(np.arange(-0.9, 0.9, 0.1))
    plt.gca().set_xticks(plt.gca().get_xticks()[::10])
    plt.xlabel('Frequency')
    plt.title('Mono Channel Histogram')

    
    plt.savefig('monoHist.png',bbox_inches="tight")
if __name__== "__main__":
    main()
