#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "screen.h"
#include "figurageometrica.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"


using namespace std;

int main()
{
    //declaracao de variaveis
    int nlin, ncol, x0ret, y0ret, x1ret, y1ret, xret, yret, alt, larg, xcirc, ycirc, raio, fillmode, n_figuras;
    char brush;

    ifstream fin;
    string linha;
    stringstream ss;
    ofstream fout;
    vector <figuraGeometrica*>  figura;


    //procura o arquivo
    fin.open("C:/Users/giovanna/Documents/gih/proj2/teste-entrada.txt");
    if (!fin.is_open()){
        //testa se o arquivo foi aberto
        cout << "arquivo nao encontrado" << endl;
        exit(0);
    }
    else{
        //se o arquivo foi aberto executa as acoes
        while(fin.good()){
            getline(fin,linha);
            if(fin.good()){
                ss.clear();
                ss.str(linha);
                while(ss.good()){
                    ss>>linha;
                    //testa o primeiro elemento para saber se eh a dimencao, reta, circulo, brush, retangulo... e salva
                    //em um vetor
                    if(linha.compare(string("Dim"))==0){
                        ss>>nlin>>ncol;
                    }
                    if(linha.compare(string("Brush"))==0){
                        ss>>brush;
                    }
                    if(linha.compare(string("Reta"))==0){
                        ss>>x0ret>>y0ret>>x1ret>>y1ret;
                        figura.push_back(new Reta(x0ret,y0ret,x1ret,y1ret));

                    }
                    if(linha.compare(string("Retangulo"))==0){
                        ss>>xret>>yret>>larg>>alt;
                        figura.push_back(new Retangulo(xret, yret, larg, alt));

                    }
                    if(linha.compare(string("Circulo"))==0){
                        ss>>xcirc>>ycirc>>raio>>fillmode;
                        figura.push_back(new Circulo(xcirc, ycirc, raio, fillmode));

                    }
                }
            }
        }
    }
    Screen screen(nlin, ncol);
    n_figuras = figura.size();
    screen.setBrush(brush);
    for (int i=0; i<n_figuras; i++){
        figura[i]->draw(screen);
    }

    cout << screen;

    //procura o arquivo de saida
    fout.open("C:/Users/giovanna/Documents/gih/proj2/teste-saida.txt");
    if(!fout.is_open()){
            //fala que o arquivo de saida não foi encontrado
            cout << "arquivo nao encontrado" << endl;
        }

    if(fout.is_open()){
        //manda para o aqruivo de saida
        fout << screen;
      }
    fout.close();
}
