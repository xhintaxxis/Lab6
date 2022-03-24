#include "bola.h"
bola::bola(float px_,float py_, float vx_, float vy_, float rad_,float masa_):
     px(px_),py(py_),vx(vx_),vy(vy_),rad(rad_),masa(masa_)
{

}

bola::~bola()
{

}
float bola::getPx() const
{
    return px;
}

void bola::setPx(float newPx)
{
    px = newPx;
}

float bola::getPy() const
{
    return py;
}

void bola::setPy(float newPy)
{
    py = newPy;
}

float bola::getVx() const
{
    return vx;
}

void bola::setVx(float newVx)
{
    vx = newVx;
}

float bola::getVy() const
{
    return vy;
}

void bola::setVy(float newVy)
{
    vy = newVy;
}

float bola::getAx() const
{
    return ax;
}

void bola::setAx(float newAx)
{
    ax = newAx;
}

float bola::getAy() const
{
    return ay;
}

void bola::setAy(float newAy)
{
    ay = newAy;
}

float bola::getRad() const
{
    return rad;
}

void bola::mover(float dt)
{
//    vx = vx+(ax*dt);
//    vy = vy+(ay*dt);
//    px += vx*dt;
//    py += vy*dt;

    px += vx*dt+0.5*dt*dt*ax;
    py += vy*dt+0.5*dt*dt*ay;
    vx = vx+(ax*dt);
    vy = vy+(ay*dt);
}

float bola::getMasa() const
{
    return masa;
}

void bola::setMasa(float newMasa)
{
    masa = newMasa;
}
