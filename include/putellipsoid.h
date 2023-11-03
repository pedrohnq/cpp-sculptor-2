#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figura_geometrica.h"

/**
 * @brief A classe PutEllipsoid representa uma operação de colocação de um elipsoide tridimensional no objeto Sculptor.
 *
 * A classe PutEllipsoid é derivada da classe FiguraGeometrica e é usada para adicionar um elipsoide tridimensional
 * a um objeto Sculptor especificado por seu centro (x, y, z) e raios (rx, ry, rz).
 *
 * Exemplo de uso da classe PutEllipsoid:
 * \code
 * #include "sculptor.h"
 * 
 * int main() {
 *     // Cria um objeto Sculptor com dimensões 10x10x10
 *     Sculptor sculptor(10, 10, 10);
 *     
 *     // Define a cor vermelha como cor padrão
 *     sculptor.setColor(1.0, 0.0, 0.0, 1.0);
 *     
 *     // Cria um elipsoide vermelho no centro da escultura com raios 3, 4 e 5
 *     PutEllipsoid putEllipsoid(5, 5, 5, 3, 4, 5, 1.0, 0.0, 0.0, 1.0);
 *     
 *     // Chama a função 'draw' para adicionar o elipsoide na escultura
 *     putEllipsoid.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class PutEllipsoid : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter; ///< Coordenadas do centro do elipsoide a ser colocado.
    int rx, ry, rz; ///< Raios do elipsoide a ser colocado.
    float r, g, b, a; ///< Cores do elipsoide a ser colocado.

public:
    /**
     * @brief Construtor da classe PutEllipsoid.
     * @param _xcenter Coordenada x do centro do elipsoide a ser colocado.
     * @param _ycenter Coordenada y do centro do elipsoide a ser colocado.
     * @param _zcenter Coordenada z do centro do elipsoide a ser colocado.
     * @param _rx Raio no eixo x do elipsoide a ser colocado.
     * @param _ry Raio no eixo y do elipsoide a ser colocado.
     * @param _rz Raio no eixo z do elipsoide a ser colocado.
     * @param _r Componente vermelha da cor do elipsoide a ser colocado.
     * @param _g Componente verde da cor do elipsoide a ser colocado.
     * @param _b Componente azul da cor do elipsoide a ser colocado.
     * @param _a Componente alfa (transparência) da cor do elipsoide a ser colocado.
     */
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe PutEllipsoid.
     */
    ~PutEllipsoid();

    /**
     * @brief Função que coloca um elipsoide tridimensional no objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde o elipsoide será colocado.
     */
    void draw(Sculptor &t);
};

#endif
