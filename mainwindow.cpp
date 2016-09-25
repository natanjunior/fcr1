#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tela->setGeometry(0, 0, 600, 600);

    marvin = new robo();
    ui->tela->setRobo(marvin);

    ui->fieldX->setText(QString::number(marvin->getX()));
    ui->fieldY->setText(QString::number(marvin->getY()));
    ui->fieldTeta->setText(QString::number(marvin->getTeta()));

    connect(this, SIGNAL(direcaoChanged(int)), ui->uSlider, SLOT(setValue(int)));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    switch (e->key()) {
    case Qt::Key_Up:
        marvin->acelerar();
        break;
    case Qt::Key_Down:
        marvin->re();
        break;
    case Qt::Key_Left:
        emit direcaoChanged(marvin->virarEsq()+45);
        break;
    case Qt::Key_Right:
        emit direcaoChanged(marvin->virarDir()+45);
        break;
    case Qt::Key_Space:
        marvin->freiar();
        break;
    default:
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e){
//    if (e->key() == Qt::Key_Shift)
//        this->setShift(0);
}
