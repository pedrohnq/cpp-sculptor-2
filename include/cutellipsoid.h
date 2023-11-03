#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figura_geometrica.h"

/**
 * @brief A classe CutEllipsoid representa uma operação de corte em forma de elipsoide tridimensional.
 *
 * A classe CutEllipsoid é derivada da classe FiguraGeometrica e é usada para realizar um corte em um espaço tridimensional
 * especificado por seu centro (x, y, z) e raios (rx, ry, rz).
 * 
 * Exemplo de uso da classe CutEllipsoid:
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
 *     // Adiciona um elipsoide vermelho no centro da escultura com raios 4, 5 e 6
 *     PutEllipsoid putEllipsoid(5, 5, 5, 4, 5, 6, 1.0, 0.0, 0.0, 1.0);
 *     putEllipsoid.draw(sculptor);
 *     
 *     // Remove o elipsoide
 *     CutEllipsoid cutEllipsoid(5, 5, 5, 4, 5, 6);
 *     cutEllipsoid.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class CutEllipsoid : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter; ///< Coordenadas do centro do elipsoide.
    int rx, ry, rz; ///< Raios do elipsoide.
    float r, g, b, a; ///< Cores da operação de corte.

public:
    /**
     * @brief Construtor da classe CutEllipsoid.
     * @param _xcenter Coordenada x do centro do elipsoide.
     * @param _ycenter Coordenada y do centro do elipsoide.
     * @param _zcenter Coordenada z do centro do elipsoide.
     * @param _rx Raio no eixo x do elipsoide.
     * @param _ry Raio no eixo y do elipsoide.
     * @param _rz Raio no eixo z do elipsoide.
     * @param _r Componente vermelha da cor da operação de corte.
     * @param _g Componente verde da cor da operação de corte.
     * @param _b Componente azul da cor da operação de corte.
     * @param _a Componente alfa (transparência) da cor da operação de corte.
     */
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe CutEllipsoid.
     */
    ~CutEllipsoid();

    /**
     * @brief Função que realiza a operação de corte em um objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a operação de corte será aplicada.
     */
    void draw(Sculptor &t);
};

#endif
