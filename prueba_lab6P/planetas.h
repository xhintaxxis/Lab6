#ifndef PLANETAS_H
#define PLANETAS_H
#include "bola.h"
#include <QPainter>
#include <QGraphicsItem>
#define DT 0.01
class planetas: public QGraphicsItem
{
public:
    planetas(float px_, float py_, float vx_, float vy_, float rad_, float masa_, float escala_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void pos(int v_lim);
    void actualizar(int v_lim);
    bola *getplaneta() const;
private:
    bola * planeta;
    float escala;

};

#endif // PLANETAS_H
