#ifndef ROBO_H
#define ROBO_H

#define fatorVirada 5.0f
#define de 0.6f //  distancia entre os eixos

class robo{
public:
    robo();
    float x;
    float y;
    float direcao;
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
};

#endif // MARVIN_H
