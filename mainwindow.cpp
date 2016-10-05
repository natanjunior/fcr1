#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tela->setGeometry(0, 0, 600, 600);

    robo = new roboPontual();
    ui->tela->setRobo(robo);

    ui->fieldX->setText(QString::number(robo->getX()));
    ui->fieldY->setText(QString::number(robo->getY()));
    ui->fieldTeta->setText(QString::number(robo->getTeta()));
    ui->fieldVelocidade->setText(QString::number(robo->getVelocidade()));
    ui->fieldDirecao->setText(QString::number(robo->getVolante()));

    connect(this, SIGNAL(direcaoChanged(int)), ui->uSlider, SLOT(setValue(int)));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    switch (e->key()) {
    case Qt::Key_Up:
        robo->acelerar();
        emit direcaoChanged(robo->getVolante());
        ui->fieldX->setText(QString::number(robo->getX()));
        ui->fieldY->setText(QString::number(robo->getY()));
        ui->fieldTeta->setText(QString::number(robo->getTeta()));
        ui->fieldVelocidade->setText(QString::number(robo->getVelocidade()));
        ui->fieldDirecao->setText(QString::number(robo->getVolante()));
        break;
    case Qt::Key_Down:
        robo->freiar();
        break;
    case Qt::Key_Left:
        emit direcaoChanged(robo->virarEsq());
        ui->fieldDirecao->setText(QString::number(robo->getVolante()));
        break;
    case Qt::Key_Right:
        emit direcaoChanged(robo->virarDir());
        ui->fieldDirecao->setText(QString::number(robo->getVolante()));
        break;
    case Qt::Key_Space:
        robo->reiniciar();
        break;
    default:
        break;
    }
    ui->tela->updateGL();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e){
//    if (e->key() == Qt::Key_Shift)
//        this->setShift(0);
}

void MainWindow::toAckerman(){
    robo = new roboAckerman();
    ui->tela->setRobo(robo);
    ui->tela->updateGL();
}

void MainWindow::toPontual(){
    robo = new roboPontual();
    ui->tela->setRobo(robo);
    ui->tela->updateGL();
}
