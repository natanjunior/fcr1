#ifndef ROBO_H
#define ROBO_H

#include <math.h>
#include <QtMath>

#define fatorVirada 5.0f
#define de 0.6f //  distancia entre os eixos

class robo{
public:
    robo();
    float xLoc;
    float yLoc;
    float xTraseira;
    float yTraseira;
    float xDianteira;
    float yDianteira;
    float direcao;
    float volante;
    float velocidade;
    void acelerar();
    void freiar();
    void re();
    int virarEsq();
    int virarDir();
    void reiniciar();
    float getX();
    float getY();
    float getTeta();
    void calculaDirecao();
    int getVolante();
};

#endif // MARVIN_H
