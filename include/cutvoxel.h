#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figura_geometrica.h"

/**
 * @brief A classe CutVoxel representa uma operação de corte em um único voxel tridimensional.
 *
 * A classe CutVoxel é derivada da classe FiguraGeometrica e é usada para realizar um corte em um único voxel
 * especificado por suas coordenadas (x, y, z).
 * 
 * Exemplo de uso da classe CutVoxel:
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
 *     // Adiciona um voxel na posição (5, 5, 5)
 *     sculptor.putVoxel(5, 5, 5);
 *     
 *     // Remove o voxel na posição (5, 5, 5)
 *     CutVoxel cutVoxel(5, 5, 5);
 *     cutVoxel.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class CutVoxel : public FiguraGeometrica {
protected:
    int x, y, z; ///< Coordenadas do voxel a ser cortado.
    float r, g, b, a; ///< Cores da operação de corte.

public:
    /**
     * @brief Construtor da classe CutVoxel.
     * @param _x Coordenada x do voxel a ser cortado.
     * @param _y Coordenada y do voxel a ser cortado.
     * @param _z Coordenada z do voxel a ser cortado.
     * @param _r Componente vermelha da cor da operação de corte.
     * @param _g Componente verde da cor da operação de corte.
     * @param _b Componente azul da cor da operação de corte.
     * @param _a Componente alfa (transparência) da cor da operação de corte.
     */
    CutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe CutVoxel.
     */
    ~CutVoxel();

    /**
     * @brief Função que realiza a operação de corte em um único voxel de um objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a operação de corte será aplicada.
     */
    void draw(Sculptor &t);
};

#endif
