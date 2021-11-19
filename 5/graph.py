import matplotlib.pyplot as plt
import math

def main():
    # Abre o ficheiro com os dados
    f = open("data.txt", "r")

    # Calcula a entropia do ficheiro
    entropy("data.txt")

    # Armazena todos os chars numa lista
    chars = []
    for line in f:
        line.split("\n")
        chars += line[0]

    print("Showing graph...")
    # Desenha o histograma com a frequência de cada char
    plt.figure(figsize=(20,10))
    # rwidth=0.5 -> espaço entre cada barra
    # bins=68 -> número de barras; existem 68 caracteres diferentes
    plt.hist(chars, rwidth=0.5, bins=68)
    plt.xlabel('Characters')
    plt.ylabel('Frequency')
    plt.title('Characters Frequency Histogram')
    plt.show()

def entropy(filename):
    with open(filename, 'rb') as f:
        byteArr = list(f.read())
    fileSize = len(byteArr)
    
    freqList = []
    for b in range(256):
        ctr = 0
        for byte in byteArr:
            if byte == b:
                ctr += 1
        freqList.append(float(ctr) / fileSize)
    
    # Shannon entropy
    ent = 0.0
    for freq in freqList:
        if freq > 0:
            ent = ent + freq * math.log(freq, 2)
    ent = -ent
    # cada byte sao 8 caracteres
    print('Shannon entropy: '+str(ent/8))

if __name__== "__main__":
    main()
