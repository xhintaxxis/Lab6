#include "planetas.h"

planetas::planetas(float px_, float py_, float vx_, float vy_, float rad_, float masa_, float escala_)
{
    escala = escala_;
    planeta = new bola(px_,py_,vx_,vy_,rad_,masa_);
}

QRectF planetas::boundingRect() const
{
    return QRectF(-1*escala*planeta->getRad(),-1*escala*planeta->getRad(),2*escala*planeta->getRad(),2*escala*planeta->getRad());
}

void planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
}

void planetas::pos(int v_lim)
{
    setPos(planeta->getPx(),v_lim-(planeta->getPy()));
}

void planetas::actualizar(int v_lim)
{
    planeta->mover(DT);
    pos(v_lim);
}

bola *planetas::getplaneta() const
{
    return planeta;
}
