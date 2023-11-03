#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figura_geometrica.h"

/**
 * @brief A classe PutVoxel representa uma operação de colocação de um voxel tridimensional no objeto Sculptor.
 *
 * A classe PutVoxel é derivada da classe FiguraGeometrica e é usada para adicionar um voxel tridimensional
 * a um objeto Sculptor especificado por suas coordenadas (x, y, z).
 * 
 * Exemplo de uso da classe PutVoxel:
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
 *     // Adiciona um voxel na posição (5, 5, 5) com a cor padrão
 *     PutVoxel putVoxel(5, 5, 5, 1.0, 0.0, 0.0, 1.0);
 *     
 *     // Chama a função 'draw' para adicionar o voxel na escultura
 *     putVoxel.draw(sculptor);
 *     
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class PutVoxel : public FiguraGeometrica {
protected:
    int x, y, z; ///< Coordenadas do voxel a ser colocado.
    float r, g, b, a; ///< Cores do voxel a ser colocado.

public:
    /**
     * @brief Construtor da classe PutVoxel.
     * @param _x Coordenada x do voxel a ser colocado.
     * @param _y Coordenada y do voxel a ser colocado.
     * @param _z Coordenada z do voxel a ser colocado.
     * @param _r Componente vermelha da cor do voxel a ser colocado.
     * @param _g Componente verde da cor do voxel a ser colocado.
     * @param _b Componente azul da cor do voxel a ser colocado.
     * @param _a Componente alfa (transparência) da cor do voxel a ser colocado.
     */
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);

    /**
     * @brief Destrutor da classe PutVoxel.
     */
    ~PutVoxel();

    /**
     * @brief Função que coloca um voxel tridimensional no objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde o voxel será colocado.
     */
    void draw(Sculptor &t);
};

#endif
