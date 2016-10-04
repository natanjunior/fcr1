#ifndef ROBOPONTUAL_H
#define ROBOPONTUAL_H

#include "robo.h"

#include <math.h>
#include <QtMath>

#define fatorVirada 5.0f
#define limiteVirada 30.0f
#define de 0.6f //  distancia entre os eixos

class roboPontual : public robo{
public:
    roboPontual();
    virtual void acelerar();
    virtual void freiar();
    virtual int virarEsq();
    virtual int virarDir();
    virtual void reiniciar();
    virtual void calculaDirecao();
};

#endif // ROBOPONTUAL_H
