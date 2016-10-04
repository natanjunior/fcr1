#ifndef CANVAS_H
#define CANVAS_H

#include <QGLWidget>
#include <QtWidgets>
#include <QtOpenGL>
#include "roboPontual.h"

class canvas : public QGLWidget{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = 0);
    ~canvas();
    robo *marvin;
    void setRobo(robo *r);
    void mover();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    float x;
    float y;
    float teta;
    void desenhaGrade();
    void desenhaRobo();
};

#endif // CANVAS_H
