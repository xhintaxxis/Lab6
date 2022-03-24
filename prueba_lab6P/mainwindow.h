#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QGraphicsItem>
#include <QFile>
#include "planetas.h"
#include <QtMath>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void aceleraciones();


private slots:
    void on_startButton_clicked();
    void actualizar();

    void on_escalar_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem * e;
    QTimer * time;
    planetas * sol;
    planetas * tierra;
    planetas * sistema[3];
    int v_limit=500;
    int h_limit=500;
};
#endif // MAINWINDOW_H
