#ifndef ROBO_H
#define ROBO_H

#define fatorVirada 5.0f
#define limiteVirada 30.0f

class robo
{
public:
    robo();
    float x0;
    float y0;
    float xLoc;
    float yLoc;
    float raio;
    float direcao;
    float volante;
    float velocidade;
    virtual void acelerar();
    virtual void freiar();
    virtual int virarEsq();
    virtual int virarDir();
    virtual void reiniciar();
    float getX();
    float getY();
    float getTeta();
    virtual void calculaDirecao();
    int getVolante();
    float getVelocidade();
    virtual float getRcolor();
    virtual float getGcolor();
    virtual float getBcolor();
};

#endif // ROBO_H
