#include "canvas.h"

#include <QDebug>

canvas::canvas(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent){

}

canvas::~canvas(){}

void canvas::setRobo(robo *r){
    this->marvin = r;
}

void canvas::mover(){
    switch (1) {
    case 1:
        if(y<9.5f)
            y=y+0.1f;
        break;
    case 2:
        if(y>-9.5f)
            y=y-0.1f;
        break;
    case 3:
        if(teta<360.0f)
            teta=teta+9.0f;
        break;
    case 4:
        if(teta>-360.0f)
            teta=teta-9.0f;
        break;
    default:
        x=0.0f;
        y=0.0f;
        break;
    }
    updateGL();
}

void canvas::desenhaGrade(){
    for(float l = -10.0f; l <= 10.0f; l=l+1.0f){
        for(float c = -10.0f; c <= 0.0f; c=c+1.0f){
            glBegin(GL_LINES);
            glColor3f(0.25f, 0.25f, 0.25f);
            glVertex3f(l, c, 0.1f);
            glVertex3f(l, c*(-1.0f), 0.1f);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.25f, 0.25f, 0.25f);
            glVertex3f(c, l, 0.1f);
            glVertex3f(c*(-1.0f), l, 0.1f);
            glEnd();
        }
    }
}

void canvas::desenhaRobo(){
    qDebug() << "x " << marvin->getX() << " y " << marvin->getY() << " d " << marvin->getTeta();
    glPushMatrix();
    glTranslatef(marvin->getX(), marvin->getY(), 0.0f);
    glRotatef(marvin->getTeta(), 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(marvin->getRcolor(), marvin->getGcolor(), marvin->getBcolor());
    glVertex3f(0.4f, 0.2f, 0.2f);
    glVertex3f(-0.4f, 0.2f, 0.2f);
    glVertex3f(-0.4f, -0.2f, 0.2f);
    glVertex3f(0.4f, -0.2f, 0.2f);
    glVertex3f(0.6f, 0.0f, 0.2f);
    glEnd();
    glPopMatrix();
}

void canvas::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    desenhaGrade();
    desenhaRobo();
}

void canvas::initializeGL(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
}

void canvas::resizeGL(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glClearColor(0, 0, 0, 1);
    glLoadIdentity();
    glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
}
