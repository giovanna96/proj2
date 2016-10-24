#ifndef RETANGULO_H
#define RETANGULO_H
#include <figurageometrica.h>

class Retangulo : public figuraGeometrica{

    int x, y, larg, alt;

public:
    Retangulo(int x, int y, int larg, int alt);
    virtual void draw(Screen &t);
    virtual void pos(void);
};

#endif // RETANGULO_H
