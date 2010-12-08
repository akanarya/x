/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 24 22:54:48 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QPushButton *genKeyButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editFileName;
    QPlainTextEdit *editComment;
    QPushButton *saveButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(380, 288);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(380, 288));
        MainWindow->setMaximumSize(QSize(380, 288));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 300, 20));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(70, 80, 300, 61));
        genKeyButton = new QPushButton(centralWidget);
        genKeyButton->setObjectName(QString::fromUtf8("genKeyButton"));
        genKeyButton->setGeometry(QRect(180, 47, 80, 25));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        genKeyButton->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 91, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 160, 61, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 200, 81, 16));
        editFileName = new QLineEdit(centralWidget);
        editFileName->setObjectName(QString::fromUtf8("editFileName"));
        editFileName->setGeometry(QRect(70, 160, 300, 20));
        editComment = new QPlainTextEdit(centralWidget);
        editComment->setObjectName(QString::fromUtf8("editComment"));
        editComment->setGeometry(QRect(70, 190, 300, 51));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(180, 250, 80, 25));
        saveButton->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(genKeyButton, SIGNAL(clicked()), MainWindow, SLOT(keyButton()));
        QObject::connect(saveButton, SIGNAL(clicked()), MainWindow, SLOT(saveButton()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Authorization Generator", 0, QApplication::UnicodeUTF8));
        genKeyButton->setText(QApplication::translate("MainWindow", "Gen Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Private Key", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "File Name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Comment", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("MainWindow", "Save File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
