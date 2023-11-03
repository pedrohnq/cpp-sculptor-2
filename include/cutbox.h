#ifndef CUTBOX_H
#define CUTBOX_H

#include "figura_geometrica.h"

/**
 * @brief A classe CutBox representa uma operação de corte em forma de caixa tridimensional.
 *
 * A classe CutBox é derivada da classe FiguraGeometrica e é usada para realizar um corte
 * em um espaço tridimensional especificado por suas coordenadas x, y e z.
 * 
 * Exemplo de uso da classe CutBox:
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
 *     // Adiciona uma caixa vermelha com vértices (2, 2, 2) e (7, 7, 7)
 *     PutBox putBox(2, 7, 2, 7, 2, 7, 1.0, 0.0, 0.0, 1.0);
 *     putBox.draw(sculptor);
 *     
 *     // Remove a caixa
 *     CutBox cutBox(2, 7, 2, 7, 2, 7);
 *     cutBox.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class CutBox : public FiguraGeometrica {
protected:
    int x0, x1, y0, y1, z0, z1; ///< Coordenadas que definem a caixa de corte.
    float r, g, b, a; ///< Cores da operação de corte.

public:
    /**
     * @brief Construtor da classe CutBox.
     * @param _x0 Coordenada x do ponto inicial da caixa de corte.
     * @param _x1 Coordenada x do ponto final da caixa de corte.
     * @param _y0 Coordenada y do ponto inicial da caixa de corte.
     * @param _y1 Coordenada y do ponto final da caixa de corte.
     * @param _z0 Coordenada z do ponto inicial da caixa de corte.
     * @param _z1 Coordenada z do ponto final da caixa de corte.
     * @param _r Componente vermelha da cor da operação de corte.
     * @param _g Componente verde da cor da operação de corte.
     * @param _b Componente azul da cor da operação de corte.
     * @param _a Componente alfa (transparência) da cor da operação de corte.
     */
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe CutBox.
     */
    ~CutBox();

    /**
     * @brief Função que realiza a operação de corte em um objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a operação de corte será aplicada.
     */
    void draw(Sculptor &t);
};

#endif
