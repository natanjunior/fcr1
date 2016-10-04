#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "robo.h"
#include "roboAckerman.h"
#include "roboPontual.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    robo *robo;

private:
    Ui::MainWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void direcaoChanged(int direcao);
};

#endif // MAINWINDOW_H
