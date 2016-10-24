#include "retangulo.h"
#include "reta.h"

Retangulo::Retangulo(int x, int y, int larg, int alt){
    //construtor da classe
    this->x = x;
    this->y = y;
    this->larg=larg;
    this->alt=alt;
}
void Retangulo::draw(Screen &t){
    //guarda os pixels onde serao desenhados
    for (int i =0; i<=larg; i++){
        t.setPixel(x+i,y);
    }

    for (int i =0; i<=larg; i++){
        t.setPixel(x+i,y+alt);
    }

    for (int i =1; i<alt; i++){
        t.setPixel(x,y+i);
    }

    for (int i =1; i<alt; i++){
        t.setPixel(x+larg,y+i);
    }
}

void Retangulo::pos(){
    cout << "(" << x << "," << y << ")" << "larg: " << larg << ",  alt: " << alt;
}
