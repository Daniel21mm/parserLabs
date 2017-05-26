#include "mainwindow.h"
#include <parser.h>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800,600);
    mainLauouy = new QGridLayout(this);

    text = new QTextEdit;
    mainLauouy->addWidget(text,1,0,1,2);

    consol = new QLineEdit;
    mainLauouy->addWidget(consol,2,1);

    go = new QPushButton;
    go->setText("Go");
    connect(go,SIGNAL(clicked(bool)),this,SLOT(goClick()));
    mainLauouy->addWidget(go,2,0);



}

void MainWindow::goClick()
{
    QString str = text->toPlainText();
    Parser p(str);
    consol->setText(p.getRezult());
//    a = 1;
//    b = 2;
//    c = 3;

//    a = a + b;
//    b  = a + c;

//    print b;
}

MainWindow::~MainWindow()
{
}


