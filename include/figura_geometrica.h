#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief A classe FiguraGeometrica é uma classe base abstrata para representar figuras geométricas.
 *
 * A classe FiguraGeometrica serve como uma classe base abstrata para todas as classes que representam figuras geométricas.
 * Ela contém uma função virtual pura 'draw' que deve ser implementada pelas classes derivadas para desenhar a figura no objeto Sculptor.
 */
class FiguraGeometrica {
public:
    /**
     * @brief Construtor da classe FiguraGeometrica.
     */
    FiguraGeometrica();

    /**
     * @brief Função virtual pura que desenha a figura no objeto Sculptor.
     * @param t Referência para um objeto Sculptor onde a figura será desenhada.
     */
    virtual void draw(Sculptor &t) = 0;

    /**
     * @brief Destrutor virtual da classe FiguraGeometrica.
     */
    virtual ~FiguraGeometrica();
};

#endif
