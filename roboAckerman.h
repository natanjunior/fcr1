#ifndef ROBOACKERMAN_H
#define ROBOACKERMAN_H

#include "robo.h"

#include <math.h>
#include <QtMath>

class roboAckerman : public robo{
public:
    roboAckerman();
    float comprimento;
    float xTraseiro;
    float yTraseiro;
    virtual void acelerar();
    virtual void freiar();
    virtual int virarEsq();
    virtual int virarDir();
    virtual void reiniciar();
    virtual void calculaDirecao();
};

#endif // ROBOACKERMAN_H
