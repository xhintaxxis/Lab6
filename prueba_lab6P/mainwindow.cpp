#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Cargar desde un archivo
    QString info;
    QFile file("C:/Users/Angel/OneDrive/Documentos/C++/Laboratorio_4/prueba_lab6P/archivos/cargar.txt");
    file.open(QIODevice::ReadOnly);
    info= file.readLine();
    QList<QString> dats;
    int n=0;
    while(n>=0){
        n=info.indexOf(" ");
        if(n!=0){
            dats.append(info.left(n));
        }
        info=info.remove(0,n+1);
    }
    for(int i=0;i<dats.size();i++){
        qDebug()<<dats.at(i);
    }

    n=0;
    h_limit=dats.at(n++).toFloat();
    v_limit=dats.at(n++).toFloat();
    while(n<dats.size()){
        if(dats.at(n)=="E"){
            sistema2.append(new planetas(dats.at(++n).toFloat(),dats.at(++n).toFloat(),dats.at(++n).toFloat(),dats.at(++n).toFloat(),dats.at(++n).toFloat(),dats.at(++n).toFloat(),2));
        }
        n++;
    }

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
   // scene->addRect(scene->sceneRect());
    for(int i=0;i<sistema2.size();i++){
        qDebug()<<sistema2.at(i)->getplaneta()->getPx();
        qDebug()<<sistema2.at(i)->getplaneta()->getPy();
        qDebug()<<sistema2.at(i)->getplaneta()->getVx();
        qDebug()<<sistema2.at(i)->getplaneta()->getVy();
        qDebug()<<sistema2.at(i)->getplaneta()->getVy();
        qDebug()<<sistema2.at(i)->getplaneta()->getMasa();
        qDebug()<<sistema2.at(i)->getplaneta()->getRad();
        sistema2.at(i)->pos(v_limit);
        scene->addItem(sistema2.at(i));
    }
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
    float axt=0;
    float ayt=0;
    double ap=0;
    double a=0;
    double b=0;
    double r=0;
    float tetha=0;
    //static double cont=0;
    for(int i=0;i<sistema2.size();i++){
        for(int j=0;j<3;j++){
            if(i!=j){
                a=sistema2.at(i)->getplaneta()->getPy()-sistema2.at(j)->getplaneta()->getPy();
                b=sistema2.at(i)->getplaneta()->getPx()-sistema2.at(j)->getplaneta()->getPx();
                tetha=atan2(a,b);
                r=(a*a)+(b*b);
                ap=(1*sistema2.at(j)->getplaneta()->getMasa())/(r);
                axt=axt+(ap*cos(tetha));
                ayt=ayt+(ap*sin(tetha));

            }
        }
        sistema2.at(i)->getplaneta()->setAx(axt);
        sistema2.at(i)->getplaneta()->setAy(ayt);
        qDebug()<<axt<<" "<<ayt;
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
//    scene->addItem(sistema[0]);
//    sistema[0]->pos(v_limit);

    sistema[1]=new planetas(0,-7000,2,0,50,70,2);
    //scene->addItem(sistema[1]);
    //sistema[1]->pos(v_limit);

    sistema[2]=new planetas(4000,5000,-1.6,1.2,60,25,2);
//    scene->addItem(sistema[2]);
//    sistema[2]->pos(v_limit);

    time=new QTimer();
    //time->stop();
    connect(time,SIGNAL(timeout()),this,SLOT(actualizar()));
    time->start(1);

}

void MainWindow::actualizar(){
    aceleraciones();
    //ui->graphicsView->scale(0.99,0.99);
    //tierra->actualizar(v_limit);
    for(int i=0;i<sistema2.size();i++){
        sistema2.at(i)->actualizar(v_limit);
        //qDebug()<<sistema[i]->getplaneta()->getPx()<<" "<<sistema[i]->getplaneta()->getPy();
    }
}

void MainWindow::on_escalar_clicked()
{
    ui->graphicsView->scale(0.5,0.5);
}

