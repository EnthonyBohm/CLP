#include <iostream>
#include <complex.h>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
    // Declaração das variáveis fora do escopo dos condicionais
    int max_iter;
    int width;
    int height;
    int i, j, k;
    complex<double> center;
    complex<double> extent;
    complex<double> c, z;
    double scale;
    
    // Atribuição dos valores passados por argumento
    if (argc == 8)  
    {
        max_iter = atoi(argv[1]);
        width = atoi(argv[2]);
        height = atoi(argv[3]);
        center = complex<double> ( atof(argv[4]), atof(argv[5]));
        extent = complex<double> ( atof(argv[6]), atof(argv[7]));
    }
    // Caso com os valores padrão, sem os argumentos, ou com número errado de argumentos
    else
    {
        max_iter = 256;
        width = 256;
        height = 256;
        center = complex<double> (-0.8, 0.0);
        extent = complex<double> (3.0, 3.0);
    }
    scale = max ( (extent / static_cast<double> (width)).real(), (extent / static_cast<double> (height)).imag());
    

    // Abertura do arquivo com os parâmetros da função
    // Salvar em um arquivo serve para manter a comunicação entre o código C e o código Python
    ofstream parameters("Parameter.txt");
    if (!parameters){
        cerr << "Error Opening File";
        return 2;
    }
    // Os parametros são salvos de forma que fica facil separalos com o metodo .split de strings
    parameters << max_iter << ";" << width << ";" << height << ";" 
    << center.real() << "+" << center.imag() << ";" 
    << extent.real() << '+' << extent.imag()<< ";"
    << scale;
    parameters.close();

    // Abertura do Arquivo que vai armazenar os valores do fractal de Mandelbrot
    ofstream outfile("MandelMatrix.txt");
    if (!outfile) {
        cerr << "Error Opening File";
        return 1;
    }

    //  Calculo do Fractal de Mandelbrodt
    for (j=0; j < height; j++)
    {
        for (i=0; i < width; i++)
        {
            c = center + complex<double>(i - (int) width / 2, (j - (int) height / 2)) * scale;
            z = 0;
            for (k = 0; k < max_iter; k++)
            {
                z = pow(z, 2) + c;
                complex<double> z_conjugate = conj(z);
                if ((z * z_conjugate).real() > 4.0) {
                    break;
                }
            }
            outfile << k;
            if (i < width - 1) outfile << " ";
        }
        outfile << endl;
    }
    
    outfile.close();
}