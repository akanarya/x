#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    fileName = "author.lic";
    comment = "//";

    ui->editFileName->setText(fileName);
    ui->editComment->appendPlainText(comment);
}

void MainWindow::keyButton(){
    lic.privateKey = ui->lineEdit->text();
    lic.genKey();
    key = lic.key;
    ui->plainTextEdit->appendPlainText(key);
}

void MainWindow::saveButton(){
    fileName = ui->editFileName->text();
    QFile file(fileName);
    bool saveStatus = true;

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);

        out << key << "\n";
        out << ui->editComment->document()->toPlainText() << "\n";

        file.close();
    } else saveStatus = false;

}

MainWindow::~MainWindow(){
    delete ui;
}
