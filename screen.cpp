#include "screen.h"

Screen::Screen(int nlin, int ncol){
        //tamanho da tela
        this -> nlin=nlin;
        this -> ncol=ncol;
        mastriz=vector < vector<char> > (nlin, vector<char> (ncol, ' '));
}


void Screen::setPixel(int x, int y){
    //pixel onde vai ser desenhado
    mastriz[x][y]=brush;
}


void Screen::clear(){
    //limpa a tela
    for (int i=0; i<nlin; i++){
        for (int j=0; j<nlin; j++){
            if(mastriz[i][j]!=' '){
                mastriz[i][j]=' ';
            }
        }
    }
}


void Screen::setBrush(char brush){
    //muda o caractere de desenho
    this -> brush=brush;
}
