from matplotlib import pyplot as plt
import numpy as np
import os

# g++ foi executado porque o gcc estava apresentando problemas pra compilar
os.system("g++ fractal.cpp -o fractal")

# Argumentos podem ser passados manualmente, porém, com o formato
# ./fractal int int int double double double double
# ex: ./fractal 256 256 256 -0.77772 0.00023 3.55 3.44  
# Caso contrário, vai rodar com os valores padrão do arquivo .c 
# Ou resultará em erro, caso os valores não correspondam ao tipo certo.
os.system("./fractal")

# A Matriz, e Em seguida os valores de parâmetros são carregados para o código Python
result = np.loadtxt("MandelMatrix.txt", dtype=int)
parameter = open("Parameter.txt")
line = parameter.readline().split(';') #Separa a string em uma lista com os parâmetros
max_iter = int (line[0])
width = int (line[1])
height = int (line[2])
center = complex (line[3]+'j') #A adição do j é para satisfazer a sintaxe do Python
extent = complex (line[4]+'j')
scale = float (line [5])
        

# Utilizando a biblioteca matplotlib, plota o gráfico.
fig, ax = plt.subplots(1, 1, figsize=(10, 10))
plot_extent = (width + 1j * height) * scale
z1 = center - plot_extent / 2
z2 = z1 + plot_extent
ax.imshow(result**(1/3), origin='lower', extent=(z1.real, z2.real, z1.imag, z2.imag))
ax.set_xlabel("$\Re(c)$")
ax.set_ylabel("$\Im(c)$")
plt.show()
