#include "robo.h"

robo::robo(){
    this->x = 0.0f;
    this->y = 0.0f;
    this->direcao = 0.0f;
    this->velocidade = 0.1f;    //  constante
}

void robo::acelerar(){

}

void robo::freiar(){

}

void robo::re(){

}

int robo::virarEsq(){
    if(direcao>=-45.0f)
        direcao-=fatorVirada;
    return direcao;
}

int robo::virarDir(){
    if(direcao<=+45.0f)
        direcao+=fatorVirada;
    return direcao;
}

void robo::reiniciar(){

}

float robo::getX(){
    return x;
}

float robo::getY(){
    return y;
}

float robo::getTeta(){
    return direcao;
}
