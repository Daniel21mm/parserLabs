#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QVector>
#include <QMap>

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    Parser(QString data);
    QString             getRezult();


signals:

public slots:
private:
    void                parsesAStringInTokens( QString str);
    QString             removingSpacesInTheBegin( QString str);
    void                fillingInTheListOfTokens(QString data);
    void                fillingInTheListOfCalculations();
    bool                isOperation(QString tokin);
    int                 priorityOfOperations(QString tokin);
    void                calculate();
    void                performingAnOperation(QString operation);
    double              valueOfVariable(QString var);

private:
    QString                 data;
    QVector <QString>       tokinList;
    QVector <QString>       listOfCalculations;
    QVector <QString>       stack;
    QString                 rezult;
    QMap <QString ,double>  listVar;


};

#endif // PARSER_H
