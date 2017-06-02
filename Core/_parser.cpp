#include "parser.h"

#include <math.h>
#include <QDebug>



Parser::Parser(QObject *parent) : QObject(parent), data("")
{

}

Parser::Parser(QString data) :
    data(data)
{
    fillingInTheListOfTokens(data);
    fillingInTheListOfCalculations();
    calculate();
}



QString Parser::getRezult()
{
    return rezult;
}


