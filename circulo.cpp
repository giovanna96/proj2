#include "circulo.h"
#include <cmath>


Circulo::Circulo(int x0, int y0, int raio, int fillmode){
    //construtor
    this->x0=x0;
    this->y0=y0;
    this ->raio=raio;
    this->fillmode=fillmode;
}

void Circulo::draw(Screen &t){
    double inverte = 1/(double)raio;
    double rec[100];
    int dx=0;
    int dy = raio-1;

    for (int i=0; i<100; i++){
        rec[i]=0;
    }
    if (fillmode==0){
        for (int i=dx; i<=dy; i++){
            //caso em que deve-se so desenhar a casca
              t.setPixel(x0-dy,y0+i);
              t.setPixel(x0-i,y0+dy);
              t.setPixel(x0+i,y0+dy);
              t.setPixel(x0+dy,y0+i);
              t.setPixel(x0+dy,y0-i);
              t.setPixel(x0+i,y0-dy);
              t.setPixel(x0-i,y0-dy);
              t.setPixel(x0-dy,y0-i);

              rec[0] = rec[0]+inverte;
              dy = raio * sin(acos(rec[0]));

         }
    }

    else {
        for (int i=raio; i>=1; i--){
            for (int j=dx; j<=dy; j++){
                //caso em que deve-se desenhar o circulo todo
                t.setPixel(x0-dy,y0+j);
                t.setPixel(x0-j,y0+dy);
                t.setPixel(x0+j,y0+dy);
                t.setPixel(x0+dy,y0+j);
                t.setPixel(x0+dy,y0-j);
                t.setPixel(x0+j,y0-dy);
                t.setPixel(x0-j,y0-dy);
                t.setPixel(x0-dy,y0-j);
                rec[i] = rec[i]+inverte;
                dy = i * sin(acos(rec[i]));
             }
        }
    }

    for (int i=0; i<100; i++){
        rec[i]=0;
    }
}

void Circulo::pos(){
    cout << "centro: ("<< x0 << "," << y0 << ")   raio: " << raio;
}
