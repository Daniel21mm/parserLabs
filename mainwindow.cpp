#include "mainwindow.h"
#include <parser.h>

#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), adressFile("")
{
    this->resize(800,600);
    mainLauouy = new QGridLayout(this);


    menu = new QHBoxLayout;
    open = new QPushButton;
    open->setText("open");
    connect(open,SIGNAL(clicked(bool)),this, SLOT(openClick()));
    menu->addWidget(open);

    save = new QPushButton;
    save->setText("save");
    connect(save,SIGNAL(clicked(bool)),this,SLOT(saveClick()));
    menu->addWidget(save);

    creater = new QPushButton;
    creater->setText("creater");
    connect(creater,SIGNAL(clicked(bool)),this,SLOT(createrClic()));
    menu->addWidget(creater);


    mainLauouy->addLayout(menu,0,0);

    text = new QTextEdit;
    mainLauouy->addWidget(text,1,0);

    consolMenu = new QHBoxLayout;

    go = new QPushButton;
    go->setText("Go");
    connect(go,SIGNAL(clicked(bool)),this,SLOT(goClick()));
    consolMenu->addWidget(go);

    consol = new QTextEdit;
    consolMenu->addWidget(consol);

    mainLauouy->addLayout(consolMenu,2,0);



}

void MainWindow::goClick()
{
    QString str = text->toPlainText();
    Parser p(str);
    consol->setText(p.getRezult());

}

void MainWindow::openClick()
{
    adressFile = QFileDialog::getOpenFileName(nullptr, "open file", "", "*.gd");
    if( !adressFile.isEmpty() )
    {
        QFile file(adressFile);
        if(file.open(QFile::ReadOnly | QFile::Text))
        {
            QString str = file.readAll();
            text->setText(str);
        }
        file.close();
    }
}

void MainWindow::saveClick()
{

}

void MainWindow::createrClic()
{

}

MainWindow::~MainWindow()
{
}


