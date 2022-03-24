#ifndef BOLA_H
#define BOLA_H
#define G 0000000000667
//0.67384x10−11

class bola
{
public:
    bola(float px_=20,float py_=20, float vx_=5, float vy_=1, float rad_=10,float masa_=5000);
    ~bola();
    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

    float getVx() const;
    void setVx(float newVx);

    float getVy() const;
    void setVy(float newVy);

    float getAx() const;
    void setAx(float newAx);

    float getAy() const;
    void setAy(float newAy);

    float getRad() const;

    void mover(float dt);

    float getMasa() const;
    void setMasa(float newMasa);

private:
    float px;
    float py;
    float vx;
    float vy;
    float ax;
    float ay;
    float rad;
    float masa;
};

#endif // BOLA_H
