#include "robo.h"

robo::robo(){
    this->xDianteira = 0.3f;
    this->xTraseira = -0.3f;
    this->yDianteira = 0.2f;
    this->yTraseira = -0.2f;
    this->direcao = 0.0f;
    this->volante = 0.0f;
    this->velocidade = 0.5f;    //  constante
}

void robo::acelerar(){
    xTraseira += velocidade*cos(direcao);
    yTraseira += velocidade*sin(direcao);
    xDianteira += velocidade*(cos(direcao+volante));
    yDianteira += velocidade*(sin(direcao+volante));
    direcao = atan2((yDianteira-yTraseira), (xDianteira-xTraseira));
//    xTraseira += velocidade;
//    xDianteira += velocidade;
//    yTraseira += velocidade;
//    yDianteira += velocidade;
//    direcao = volante;
}

void robo::freiar(){

}

void robo::re(){

}

int robo::virarEsq(){
    if(volante>=-45.0f)
        volante-=fatorVirada;
    return volante;
}

int robo::virarDir(){
    if(volante<=+45.0f)
        volante+=fatorVirada;
    return volante;
}

void robo::reiniciar(){

}

float robo::getX(){
    return (xDianteira+xTraseira)/2;
}

float robo::getY(){
    return (xDianteira+xTraseira)/2;
}

float robo::getTeta(){
    return direcao;
}
