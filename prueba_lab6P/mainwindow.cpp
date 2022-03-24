#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit=250;
    v_limit=250;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit*2,v_limit*2);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aceleraciones()
{
    /*float num=(sol->getplaneta()->getPy()-tierra->getplaneta()->getPy())*28;
    float den=(sol->getplaneta()->getPx()-tierra->getplaneta()->getPx())*28;
    //if(den<0){den=-1*den;}
    //if(num<0){den=-1*den;}
    float tetha=atan(num/den);
    double a = (sol->getplaneta()->getPx()-tierra->getplaneta()->getPx())*(sol->getplaneta()->getPx()-tierra->getplaneta()->getPx())*28*28;
    double b = (sol->getplaneta()->getPy()-tierra->getplaneta()->getPy())*(sol->getplaneta()->getPy()-tierra->getplaneta()->getPy())*28*28;
    double r = sqrt(a+b);
    double ax1 = (G*sol->getplaneta()->getMasa()*cos(tetha))/(r*r);
    double ay1 = (G*sol->getplaneta()->getMasa()*sin(tetha))/(r*r);
    tierra->getplaneta()->setAx(ax1);
    tierra->getplaneta()->setAy(ay1);
    qDebug()<<tetha*180/3.1415<<" "<<num/den<<" "<<ax1<<" "<<ay1<<" "<<tierra->getplaneta()->getPx()<<" "<<tierra->getplaneta()->getPy();*/
    double axt=0;
    double ayt=0;
    double ap=0;
    double a=0;
    double b=0;
    double r=0;
    float tetha=0;
    static double cont=0;
    for(int i=1;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j){
                a=sistema[j]->getplaneta()->getPy()-sistema[i]->getplaneta()->getPy();
                b=sistema[j]->getplaneta()->getPx()-sistema[i]->getplaneta()->getPx();
                tetha=atan(a/b);
                r=sqrt(a*a+b*b);
                ap=(G*sistema[j]->getplaneta()->getMasa())/(r*r);
                axt=axt+ap*cos(tetha);
                ayt=ayt+ap*sin(tetha);
                qDebug()<<cont++;
            }
        }
        sistema[i]->getplaneta()->setAx(axt);
        sistema[i]->getplaneta()->setAy(ayt);
        axt=0;
        ayt=0;
    }

}


void MainWindow::on_startButton_clicked()
{

    //static int cont=0;
    //e = scene->addEllipse(-25,-25,50,50);
    //e->setPos(250+cont,250+cont);
//    sol = new planetas(h_limit/2,v_limit/2,0,0,20,70000,2);
//    scene->addItem(sol);
//    sol->pos(v_limit);

//    tierra = new planetas(8000/28,1000/28,200,100,5,30,2);
//    scene->addItem(tierra);
//    tierra->pos(v_limit);

    sistema[0]=new planetas(0,0,0,0,20,70000,2);
    scene->addItem(sistema[0]);
    sistema[0]->pos(v_limit);

    sistema[1]=new planetas(8000/28,1000/28,2,0,5,70,2);
    scene->addItem(sistema[1]);
    sistema[1]->pos(v_limit);

    sistema[2]=new planetas(12000/28,13000/28,-1.6,1.2,10,25,2);
    scene->addItem(sistema[2]);
    sistema[2]->pos(v_limit);


    time=new QTimer();
    time->stop();
    connect(time,SIGNAL(timeout()),this,SLOT(actualizar()));
    time->start(100);

}

void MainWindow::actualizar(){
    //aceleraciones();
    //ui->graphicsView->scale(0.99,0.99);
    //tierra->actualizar(v_limit);
    for(int i=1;i<3;i++){
        sistema[i]->actualizar(v_limit);
        //qDebug()<<sistema[i]->getplaneta()->getPx()<<" "<<sistema[i]->getplaneta()->getPy();
    }
}

void MainWindow::on_escalar_clicked()
{
    ui->graphicsView->scale(0.5,0.5);
}

