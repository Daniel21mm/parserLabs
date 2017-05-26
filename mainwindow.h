#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void goClick();
    void openClick();
    void saveClick();
    void createrClic();

private:

    QGridLayout* mainLauouy;

    QHBoxLayout* menu;
    QPushButton* open;
    QPushButton* save;
    QPushButton* creater;

    QTextEdit*   text;

    QHBoxLayout* consolMenu;
    QTextEdit*   consol;
    QPushButton* go;


    QString      adressFile;

};

#endif // MAINWINDOW_H
