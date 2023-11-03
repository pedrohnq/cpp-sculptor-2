#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @struct Voxel
 * @brief Estrutura que representa um voxel tridimensional.
 */
struct Voxel {
    float r, g, b; ///< Componentes de cor (vermelho, verde e azul) do voxel.
    float a; ///< Componente alfa (transparência) do voxel.
    bool show; ///< Indica se o voxel está visível ou não.
};

/**
 * @class Sculptor
 * @brief A classe Sculptor representa um objeto tridimensional (escultura) composto por voxels.
 *
 * Exemplo de uso da classe Sculptor:
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
 *     // Escreve a escultura em um arquivo no formato OFF
 *     sculptor.writeOFF("escultura.off");
 *     
 *     return 0;
 * }
 * \endcode
 */
class Sculptor {
protected:
    Voxel ***v; ///< Matriz tridimensional de voxels.
    int nx, ny, nz; ///< Dimensões da escultura tridimensional (nx, ny, nz).
    float r, g, b, a; ///< Cores padrão para desenhar os voxels.

public:
    /**
     * @brief Construtor da classe Sculptor.
     * @param _nx Número de voxels na dimensão x.
     * @param _ny Número de voxels na dimensão y.
     * @param _nz Número de voxels na dimensão z.
     */
    Sculptor(int _nx, int _ny, int _nz);

    /**
     * @brief Destrutor da classe Sculptor.
     */
    ~Sculptor();

    /**
     * @brief Define a cor padrão para desenhar os voxels.
     * @param r Componente vermelha da cor.
     * @param g Componente verde da cor.
     * @param b Componente azul da cor.
     * @param a Componente alfa (transparência) da cor.
     */
    void setColor(float r, float g, float b, float a);

    /**
     * @brief Ativa um voxel na posição especificada e atribui a ele a cor padrão.
     * @param x Coordenada x do voxel.
     * @param y Coordenada y do voxel.
     * @param z Coordenada z do voxel.
     */
    void putVoxel(int x, int y, int z);

    /**
     * @brief Desativa um voxel na posição especificada, tornando-o transparente.
     * @param x Coordenada x do voxel.
     * @param y Coordenada y do voxel.
     * @param z Coordenada z do voxel.
     */
    void cutVoxel(int x, int y, int z);

    /**
     * @brief Escreve a escultura em um arquivo no formato OFF.
     * @param filename Nome do arquivo onde a escultura será escrita.
     */
    void writeOFF(const char *filename);
};

#endif
