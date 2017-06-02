#include "parser.h"

void Parser::fillingInTheListOfTokens(QString data)
{
    QString rest = data.replace("\n"," ");
            rest = rest.replace("\t"," ");
            rest = rest.trimmed();
    while(  rest != "")
    {
        QString  current = rest.left(rest.indexOf(";"));
        if(current != "")
            parsesAStringInTokens(current);
        rest = rest.mid(rest.indexOf(";")+ 1,rest.size());
    }


}


void Parser::parsesAStringInTokens(QString str)
{
    str = removingSpacesInTheBegin(str) + " ";
    QString tokin = "";
    for (int i(0); i < str.size(); i++)
    {
        QString currentChar = str.at(i);
        if( (currentChar != " ") &&  ("\"" != currentChar) )
        {
            tokin += currentChar;
        }
        else if( "\"" == currentChar )
        {
            tokin = getInternalString(str);
            tokinList.push_back(tokin);
            tokin = "";
        }
        else
        {
            if( tokin != "" )
                tokinList.push_back(tokin);
            tokin = "";
        }


    }
    tokinList.push_back(";");


}

QString Parser::removingSpacesInTheBegin(QString str)
{
    int index = 0;
    while(" " == str.at(index))
        index++;
    return str.mid(index,str.size());

}

QString Parser::getInternalString(QString& str) //получение подстроки для вынисения в токен
{
    QString localStr = str.mid(str.indexOf("\"")+1,str.size());  // локальная строка = строка исходная от после первой ковычки и до конца
    QString tokin = "\"" + localStr.mid(0, localStr.indexOf("\"")+1); // токен = " + локСтр от начала до ковычки с ее учетом
    str = localStr.mid(localStr.indexOf("\"")+1, localStr.size() ); // строка текущая = локСтрока от полсе второй ковычки и до  конца
    return tokin;

}
