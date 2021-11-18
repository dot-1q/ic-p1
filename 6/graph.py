import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FormatStrFormatter
import pandas as pd
import math
from matplotlib.ticker import StrMethodFormatter

def main():
    #file = open("left.txt","r")
    data = pd.read_csv('left.txt', sep=',',header=None, index_col =0)

    data.plot(kind='bar')
    plt.ylabel('Frequency')
    #plt.xticks(np.arange(-0.9, 0.9, 0.1))
    plt.gca().set_xticks(plt.gca().get_xticks()[::10])
    plt.xlabel('Words')
    plt.title('Title')

    plt.show()

if __name__== "__main__":
    main()
