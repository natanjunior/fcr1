#include "robo.h"

#include <QDebug>

robo::robo(){
    this->xDianteira = 0.3f;
    this->xTraseira = -0.3f;
    this->yDianteira = 0.2f;
    this->yTraseira = -0.2f;
    this->direcao = 0.0f;
    this->volante = 0.0f;
    this->velocidade = 0.5f;    //  constante
}

void robo::calculaDirecao(){
    direcao += volante;
    if(direcao>=360){
        direcao = 0;
    }else if (direcao<0){
        direcao = 355;
    }
    if(volante>0){
        volante -= fatorVirada;
    }else if(volante<0){
        volante += fatorVirada;
    }
}

void robo::acelerar(){
    calculaDirecao();
    xTraseira += velocidade*cos(direcao);
    yTraseira += velocidade*sin(direcao);
    xDianteira += velocidade*sin(direcao+volante);
    yDianteira += velocidade*cos(direcao+volante);
//    direcao = atan2((yDianteira-yTraseira), (xDianteira-xTraseira));
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
    if(volante>-45.0f)
        volante-=fatorVirada;
    return volante+45;
}

int robo::virarDir(){
    if(volante<45.0f)
        volante+=fatorVirada;
    return volante+45;
}

int robo::getVolante(){
    return volante+45;
}

void robo::reiniciar(){

}

float robo::getX(){
//    return xDianteira;
    return (xDianteira+xDianteira)/2;
}

float robo::getY(){
//    return yDianteira;
    return (yDianteira+yDianteira)/2;
}

float robo::getTeta(){
    return direcao;
}

float robo::getVelocidade(){
    return velocidade;
}
