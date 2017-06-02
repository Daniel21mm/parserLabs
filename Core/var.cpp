#include "parser.h"

Parser::Var::Var()
    :type(Type::NIL),data("nil")
{

}

Parser::Var::Var(QString data)
{

}

Parser::Var::Var(Parser::Var::Type type, QString data)
    :type(type), data(data)
{

}

Parser::Var::Var(const Parser::Var & v)
    :type(v.type),data(v.data)
{

}

Parser::Var &Parser::Var::operator=(const Parser::Var & v)
{
    if( this != &v) //проверка на самоприсваивание
    {
        type = v.type;
        data = v.data;
    }
    return *this;

}

QString Parser::Var::getDataVar()
{
    return data;
}



Parser::Var::Type Parser::Var::getType()
{
    return type;
}

Parser::Var::Type Parser::Var::isType(QString _data)
{


    if( isNumeric( _data ) )
    {
       return Type::NUMERIC;
    }
    else if( _data == "true" || _data == "false" )
    {
        return Type::BOOL;
    }
    else if(  isString( _data )  )
    {
        return Type::STRING;
    }
    else
    {
        return Type::NIL;
    }

}

bool Parser::Var::isNumeric( QString _data )
{
    bool isDoble = true;
    _data.toDouble(&isDoble);
    return isDoble;

}

bool Parser::Var::isString( QString _data )
{
    return ( (  "\"" == _data.at(0) ) && ( "\"" == _data.at(_data.size()-1)  ) );
}
