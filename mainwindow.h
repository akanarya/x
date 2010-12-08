#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "protect.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    protect lic;
    QString key;
    QString fileName;
    QString comment;

private slots:
    void keyButton();
    void saveButton();
};

#endif // MAINWINDOW_H
