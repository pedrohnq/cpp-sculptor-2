#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figura_geometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutSphere representa uma operação de colocação de uma esfera tridimensional no objeto Sculptor.
 *
 * A classe PutSphere é derivada da classe FiguraGeometrica e é usada para adicionar uma esfera tridimensional
 * a um objeto Sculptor especificado por seu centro (x, y, z) e raio.
 * 
 * Exemplo de uso da classe PutSphere:
 * \code
 * int main() {
 *    Sculptor sculptor(10, 10, 10);
 *    
 *    // Cria uma esfera vermelha com raio 3 no centro da escultura
 *    PutSphere putSphere(5, 5, 5, 3, 1.0, 0.0, 0.0, 1.0);
 *    
 *    // Chama a função 'draw' para adicionar a esfera na escultura
 *    putSphere.draw(sculptor);
 *    
 *    sculptor.writeOFF("escultura.off");
 *    
 *    return 0;
 * }
 * \endcode
 */
class PutSphere : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter; ///< Coordenadas do centro da esfera a ser colocada.
    int radius; ///< Raio da esfera a ser colocada.
    float r, g, b, a; ///< Cores da esfera a ser colocada.

public:
    /**
     * @brief Construtor da classe PutSphere.
     * @param _xcenter Coordenada x do centro da esfera a ser colocada.
     * @param _ycenter Coordenada y do centro da esfera a ser colocada.
     * @param _zcenter Coordenada z do centro da esfera a ser colocada.
     * @param _radius Raio da esfera a ser colocada.
     * @param _r Componente vermelha da cor da esfera a ser colocada.
     * @param _g Componente verde da cor da esfera a ser colocada.
     * @param _b Componente azul da cor da esfera a ser colocada.
     * @param _a Componente alfa (transparência) da cor da esfera a ser colocada.
     */
    PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe PutSphere.
     */
    ~PutSphere();

    /**
     * @brief Função que coloca uma esfera tridimensional no objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a esfera será colocada.
     */
    void draw(Sculptor &t);
};

#endif
