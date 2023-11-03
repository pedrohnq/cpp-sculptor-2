#ifndef PUTBOX_H
#define PUTBOX_H

#include "figura_geometrica.h"
#include "sculptor.h"

/**
 * @brief A classe PutBox representa uma operação de colocação de uma caixa tridimensional no objeto Sculptor.
 *
 * A classe PutBox é derivada da classe FiguraGeometrica e é usada para adicionar uma caixa tridimensional
 * a um objeto Sculptor especificado por suas coordenadas x, y e z.
 * 
 * Exemplo de uso da classe PutBox:
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
 *     // Cria uma caixa vermelha com vértices (1, 1, 1) e (8, 8, 8)
 *     PutBox putBox(1, 8, 1, 8, 1, 8, 1.0, 0.0, 0.0, 1.0);
 *     
 *     // Chama a função 'draw' para adicionar a caixa na escultura
 *     putBox.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class PutBox : public FiguraGeometrica {
protected:
    int x0, x1, y0, y1, z0, z1; ///< Coordenadas que definem a caixa a ser colocada.
    float r, g, b, a; ///< Cores da caixa a ser colocada.

public:
    /**
     * @brief Construtor da classe PutBox.
     * @param _x0 Coordenada x do ponto inicial da caixa a ser colocada.
     * @param _x1 Coordenada x do ponto final da caixa a ser colocada.
     * @param _y0 Coordenada y do ponto inicial da caixa a ser colocada.
     * @param _y1 Coordenada y do ponto final da caixa a ser colocada.
     * @param _z0 Coordenada z do ponto inicial da caixa a ser colocada.
     * @param _z1 Coordenada z do ponto final da caixa a ser colocada.
     * @param _r Componente vermelha da cor da caixa a ser colocada.
     * @param _g Componente verde da cor da caixa a ser colocada.
     * @param _b Componente azul da cor da caixa a ser colocada.
     * @param _a Componente alfa (transparência) da cor da caixa a ser colocada.
     */
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe PutBox.
     */
    ~PutBox();

    /**
     * @brief Função que coloca uma caixa tridimensional no objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a caixa será colocada.
     */
    void draw(Sculptor &t);
};

#endif
