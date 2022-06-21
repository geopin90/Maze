#include "mainwindow.h"
#include "../src/Maze/Controller/Controller.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    s21::InitMaze myMaze;
    s21::Controller myController(&myMaze);
    MainWindow w(&myController);
    w.show();
    return a.exec();
}
