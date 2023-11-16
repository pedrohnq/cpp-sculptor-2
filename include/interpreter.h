#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <vector>
#include "figura_geometrica.h"
#include <string>
using namespace std;

class Interpreter
{
    int dimx,dimy,dimz;
    float r,g,b,a;
public:
    Interpreter();
    ~Interpreter(){};

    /**
    * @brief Classe responsável por interpretar um arquivo de texto.
    * @details Cria uma figura com base em cada linha do arquivo
    * @param filename Título do arquivo de texto.
    */
    vector<FiguraGeometrica*> read(string filename);

    /**
    * @brief Método get da dimensão x.
    * @details Retorna o tamanho da dimensão x.
    */
    int getdimx();
    /**
    * @brief Método get da dimensão y.
    * @details Retorna o tamanho da dimensão y.
    */
    int getdimy();
    /**
    * @brief Método get da dimensão z.
    * @details Retorna o tamanho da dimensão z.
    */
    int getdimz();
};

#endif