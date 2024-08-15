## Informações Basicas
A aplicação gráfica escolhida para ser representada foi o Fractal de Mandelbrot.

Antes de executar o script em Python, só dois arquivos compõem o repositório.
O arquivo de script em Python, que irá rodar o arquivo C++, e gerar a interface gráfica.
E o arquivo em C. que realizará o calculo e irá gerar mais dois arquivos.

O primeiro arquivo é o de parâmetros, que vão ser posteriormente utilizados no programa Python.
O segundo arquivo é uma matriz com o resultado dos cálculos do fractal de Mandelbrot.

Ao final da execução. a imagem gerada não será salva por padrão. Se finalizar a execução, a representação gráfica do fractal é perdida.

## Bibliotecas Necessárias
Para ser possível implementar essa solução, foram utilizadas as seguintes bibliotecas Python
* os : necessária para compilar e executar o código em C++;
* numpy : necessária para utilizar matrizes. Nesse caso, a matriz de resultado do Mandelbrot/;
* matplotlib : responsável por fornecer a interface gráfica.

Assim como, as seguintes bibliotecas em C++:
* iostream : biblioteca padrão de C++;
* complex.h : tornando possível o uso de números complexos;
* math.h : uso de operação matemáticas, como potência;
* fstream : para manipulação em arquivos.

## Execução 
Para executar o código, basta rodar o programa em Python.
Ou então, executar o makefile, de qualquer forma, o resultado será o mesmo. Para modificar o caso de teste, a modificação deve ser no próprio programa Python, na passagem de argumentos.
Tanto com a versão padrão dele, que já tem um caso de teste. Quanto colocando valores arbitrários de argumento para a execução do código C.
