#ifndef SRC_MAZE_VIEW_MAINWINDOW_H_
#define SRC_MAZE_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QString>
#include "../Controller/Controller.h"
#include "../Model/FindPath.h"
#include "../View/DrawMaze.h"
#include "../View/ErrorDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(s21::Controller* mainControl, QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void on_openButton_clicked();

    void on_generateButton_clicked();

    void on_findPathButton_clicked();

    void on_saveButton_clicked();

 private:
    Ui::MainWindow *ui;
};
#endif  // SRC_MAZE_VIEW_MAINWINDOW_H_
