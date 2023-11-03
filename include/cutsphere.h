#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figura_geometrica.h"

/**
 * @brief A classe CutSphere representa uma operação de corte em forma de esfera tridimensional.
 *
 * A classe CutSphere é derivada da classe FiguraGeometrica e é usada para realizar um corte em um espaço tridimensional
 * especificado por seu centro (x, y, z) e raio.
 * 
 * Exemplo de uso da classe CutSphere:
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
 *     // Adiciona uma esfera vermelha no centro da escultura com raio 4
 *     PutSphere putSphere(5, 5, 5, 4, 1.0, 0.0, 0.0, 1.0);
 *     putSphere.draw(sculptor);
 *     
 *     // Remove a esfera
 *     CutSphere cutSphere(5, 5, 5, 4);
 *     cutSphere.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class CutSphere : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter; ///< Coordenadas do centro da esfera.
    int radius; ///< Raio da esfera.
    float r, g, b, a; ///< Cores da operação de corte.

public:
    /**
     * @brief Construtor da classe CutSphere.
     * @param _xcenter Coordenada x do centro da esfera.
     * @param _ycenter Coordenada y do centro da esfera.
     * @param _zcenter Coordenada z do centro da esfera.
     * @param _radius Raio da esfera.
     * @param _r Componente vermelha da cor da operação de corte.
     * @param _g Componente verde da cor da operação de corte.
     * @param _b Componente azul da cor da operação de corte.
     * @param _a Componente alfa (transparência) da cor da operação de corte.
     */
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe CutSphere.
     */
    ~CutSphere();

    /**
     * @brief Função que realiza a operação de corte em um objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a operação de corte será aplicada.
     */
    void draw(Sculptor &t);
};

#endif
