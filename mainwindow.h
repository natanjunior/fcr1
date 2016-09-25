#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "robo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    robo *marvin;

private:
    Ui::MainWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void direcaoChanged(int teta);
};

#endif // MAINWINDOW_H
