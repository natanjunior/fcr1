#include "robo.h"

#include <QDebug>

robo::robo(){
    xLoc = x0 = 0;
    yLoc = y0 = 0;
    raio = 0;

    this->xDianteira = 0.3f;
    this->xTraseira = -0.3f;
    this->yDianteira = 0.2f;
    this->yTraseira = -0.2f;
    this->direcao = 0.0f;
    this->volante = 0.0f;
    this->velocidade = 0.5f;    //  constante
}

void robo::calculaDirecao(){
    direcao -= volante;
    if(direcao>360.0f){
        direcao = volante*(-1);
    }else if (direcao<0.0f){
        direcao = 360.0f-volante;
    }
//    if(volante>0){
//        volante -= fatorVirada;
//    }else if(volante<0){
//        volante += fatorVirada;
//    }
    volante = 0;
}

void robo::acelerar(){
    if(volante!=0)
        calculaDirecao();
    raio += velocidade;
    xLoc = x0+raio*cos(qDegreesToRadians(direcao));
    yLoc = y0+raio*sin(qDegreesToRadians(direcao));
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
    if(volante>-limiteVirada)
        volante-=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

int robo::virarDir(){
    if(volante<limiteVirada)
        volante+=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

int robo::getVolante(){
    return volante;
}

void robo::reiniciar(){

}

float robo::getX(){
    return xLoc;
//    return (xDianteira+xDianteira)/2;
}

float robo::getY(){
    return yLoc;
//    return (yDianteira+yDianteira)/2;
}

float robo::getTeta(){
    return direcao;
}

float robo::getVelocidade(){
    return velocidade;
}
