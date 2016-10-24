#include "reta.h"

Reta::Reta(int x0, int y0, int x1, int y1){
    //construtor da classe
    this->x0=x0;
    this->y0=y0;
    this->x1=x1;
    this->y1=y1;
}

void Reta::draw(Screen &t){ //ajeitar o eixo x e o eixo y, estao trocados
    //salva as coordenadas dos pixels que serao desenhados
    int xf, yf, xi, yi;
    float xi1, yi1;
    float angulo;

    xi=x1-x0;
    yi=y1-y0;
    xi1=xi;
    yi1=yi;

    if (xi1 >= yi1){
        angulo = yi1/xi1;
        for(int i=0; i<xi; i++){
            xf=x0+i;
            yf=angulo*i+y0;
            t.setPixel(xf,yf);
        }
    }

    else {
        angulo = xi1/yi1;
        for (int i=0; i<yi; i++){
            xf=angulo*i+x0;
            yf=y0+i;
            t.setPixel(xf,yf);
        }
    }
}

void Reta::pos(){
    cout <<"(" << x0 << "," << y0 << ") -> (" << x1 << "," << y1 << ")";
}
