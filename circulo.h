#ifndef CIRCULO_H
#define CIRCULO_H
#include <figuraeometrica.h>

class Circulo : public figuraGeometrica{

    int x0,y0,raio,fillmode;

public:

    Circulo(int x0, int y0, int raio, int fillmode);
    virtual void draw(Screen &t);
    virtual void pos(void);
};

#endif // CIRCULO_H
