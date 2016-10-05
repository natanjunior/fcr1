#include "roboPontual.h"

#include <QDebug>

roboPontual::roboPontual() : robo(){
    xLoc = x0 = 0;
    yLoc = y0 = 0;
    raio = 0;

    direcao = 0.0f;
    volante = 0.0f;
    velocidade = 0.5f;
}

void roboPontual::calculaDirecao(){
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

void roboPontual::acelerar(){
    if(volante!=0)
        calculaDirecao();
    raio += velocidade;
    xLoc = x0+raio*cos(qDegreesToRadians(direcao));
    yLoc = y0+raio*sin(qDegreesToRadians(direcao));
}

int roboPontual::virarEsq(){
    if(volante>-limiteVirada)
        volante-=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

int roboPontual::virarDir(){
    if(volante<limiteVirada)
        volante+=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

void roboPontual::reiniciar(){

}

void roboPontual::freiar(){

}
