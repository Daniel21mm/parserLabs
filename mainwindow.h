#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void goClick();

private:

    QGridLayout* mainLauouy;
    QTextEdit*   text;
    QLineEdit*   consol;
    QPushButton* go;


};

#endif // MAINWINDOW_H
