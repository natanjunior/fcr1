#include "roboAckerman.h"

#include <QDebug>

roboAckerman::roboAckerman() : robo(){
    xLoc = x0 = 0;
    yLoc = y0 = 0;
    raio = 0;
    direcao = 0.0f;
    volante = 0.0f;
    comprimento = 1.0f;
    velocidade = 0.5f;
}


void roboAckerman::calculaDirecao(){
    raio = comprimento / tan(volante);
    direcao += comprimento / raio;
//    direcao -= volante;
//    if(direcao>360.0f){
//        direcao = volante*(-1);
//    }else if (direcao<0.0f){
//        direcao = 360.0f-volante;
//    }
    if(volante>0){
        x0-=raio;
        y0-=raio;
    }else if(volante<0){
        x0+=raio;
        y0+=raio;
    }
    qDebug() << raio << " " << direcao;
//    raio = 0;
//    xLoc = x0+(xLoc-x0)*cos(direcao)-(yLoc-y0)*sin(direcao);
//    yLoc = y0+(xLoc-x0)*sin(direcao)+(yLoc-y0)*cos(direcao);
    volante=0;
}

void roboAckerman::acelerar(){
    if(volante!=0)
        calculaDirecao();
    else
        raio += velocidade;
    xLoc = x0+raio*cos(qDegreesToRadians(direcao));
    yLoc = y0+raio*sin(qDegreesToRadians(direcao));

}

int roboAckerman::virarEsq(){
    if(volante>-limiteVirada)
        volante-=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

int roboAckerman::virarDir(){
    if(volante<limiteVirada)
        volante+=fatorVirada;
    x0 = xLoc;
    y0 = yLoc;
    raio = 0;
    return volante;
}

void roboAckerman::reiniciar(){

}

void roboAckerman::freiar(){

}
