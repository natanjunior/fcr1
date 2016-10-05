#ifndef ROBOPONTUAL_H
#define ROBOPONTUAL_H

#include "robo.h"

#include <math.h>
#include <QtMath>

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
