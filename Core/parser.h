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
    class Var
    {
    public:
        enum Type{ NIL = 0,
                   NUMERIC = 1,
                   BOOL = 2,
                   STRING = 3 };
    public:
        Var();
        Var(QString);
        Var(Type,QString);
        Var(const Var&);
        Var&    operator= (const Var&);

        QString getDataVar();
        Type    getType();
    private:
        Type    isType(QString);
        bool    isNumeric(QString);
        bool    isString(QString);

    private:
        Type        type;
        QString     data;
    };
private:

    // tokenizer.cpp
    void                fillingInTheListOfTokens(QString data);
    void                parsesAStringInTokens( QString str);
    QString             removingSpacesInTheBegin( QString str);
    QString             getInternalString(QString& str );

    // interpreter.cpp
    void                fillingInTheListOfCalculations();
    bool                isOperation(QString tokin);
    int                 priorityOfOperations(QString tokin);

    // calculate.cpp

    void                calculate();
    void                performingAnOperation(QString operation);
    double              valueOfVariable(QString var);
    QVector<QString>    getRegion();

private:
    QString                 data;
    QVector <QString>       tokinList;
    QVector <QString>       listOfCalculations;
    QVector <QString>       stack;
    QString                 rezult;
    QMap <QString ,double>  listVar;


};

#endif // PARSER_H



