#ifndef CANVAS_H
#define CANVAS_H


class canvas : public QGLWidget{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();
};

#endif // CANVAS_H
