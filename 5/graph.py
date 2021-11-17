import matplotlib.pyplot as plt
import numpy as np

# Abre o ficheiro com os dados
f = open("data.txt", "r")

# Armazena todos os chars numa lista
chars = []
for line in f:
    line.split("\n")
    chars += line[0]

# Desenha o histograma com a frequência de cada char
plt.figure(figsize=(20,10))
# rwidth=0.5 -> espaço entre cada barra
# bins=68 -> número de barras; existem 68 caracteres diferentes
plt.hist(chars, rwidth=0.5, bins=68)
plt.xlabel('Characters')
plt.ylabel('Frequency')
plt.title('Characters Frequency Histogram')
plt.show()