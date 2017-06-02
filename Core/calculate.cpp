#include "parser.h"

#include <math.h>


void Parser::calculate()
{

    listOfCalculations.push_back("");
    while(!listOfCalculations.empty())
    {
        QString tokin = listOfCalculations.front();
        if( tokin == "if" || tokin == "else" || tokin == "repeat" )
        {
            performingAnOperation( tokin);
        }
        else if(  isOperation(tokin)   )
        {
            performingAnOperation( tokin);
            listOfCalculations.pop_front();


        }
        else
        {
            stack.push_back(tokin);
            listOfCalculations.pop_front();
        }
    }

}


void Parser::performingAnOperation(QString operation)
{
    if(operation == "print")
    {
        rezult += QString::number( valueOfVariable( stack.back() ) ) + "\n";
        stack.pop_back();
    }
    else if(operation == "if")
    {
        listOfCalculations.pop_front();

        QVector<QString> regionIf = getRegion();
        QVector<QString> regionElse;
        if( listOfCalculations.front() == "else" )
        {
            listOfCalculations.pop_front();
            regionElse = getRegion();
        }

        if(stack.back() == "true")
        {
            listOfCalculations = regionIf + listOfCalculations;
        }
        else if( stack.back() == "false")
        {
            listOfCalculations = regionElse + listOfCalculations;
        }
        stack.pop_back();

    }
    else if( operation == "repeat" )
    {
        listOfCalculations.pop_front();
        QVector <QString> regionRepeat = getRegion();
        int amount = static_cast<int>(valueOfVariable(stack.back()));
        stack.pop_back();
        for(int i(0); i < amount ; i++ )
        {
            listOfCalculations = regionRepeat + listOfCalculations;
        }


    }
    else if( operation == "(" ||  operation == ")" )
        return ;
    else if( operation == "=")
    {
        QString rightOperands = stack.back();
        stack.pop_back();
        QString leftOperands = stack.back();
        stack.pop_back();

        bool flag = true;
        listVar[leftOperands] = rightOperands.toDouble(&flag);

        // if(!flag)
        //throw;
    }
    else if(operation == "<")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands < rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if(operation == ">" )
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands > rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if(operation == "==")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands == rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if(operation == "!=" )
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands != rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if(operation == ">=" )
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands >= rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if(operation == "=<")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();

        if( leftOperands < rightOperands)
        {
            stack.push_back("true");
        }
        else
        {
            stack.push_back("false");
        }
    }
    else if( operation == "+")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        stack.push_back(QString::number(  leftOperands + rightOperands  ));

    }
    else if( operation == "-")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        stack.push_back(QString::number(  leftOperands - rightOperands  ));

    }
    else if(  operation == "*")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        stack.push_back(QString::number(  leftOperands * rightOperands  ));

    }
    else if( operation == "/" )
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        stack.push_back(QString::number(  leftOperands / rightOperands  ));

    }
    else if( operation == "^")
    {
        double rightOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        double leftOperands = valueOfVariable( stack.back() );
        stack.pop_back();


        stack.push_back(QString::number(  pow(leftOperands, rightOperands)  ));
    }
    else if(operation == "sqrt")
    {
        double var = valueOfVariable( stack.back() );
        stack.pop_back();

        stack.push_back( QString::number(sqrt(var)));
    }

        return;
}

double Parser::valueOfVariable(QString var)
{
    bool flag = true;
    double value = var.toDouble(&flag);
    if(!flag)
    {
        value = listVar[var];
    }
    return value;
}

QVector<QString> Parser::getRegion()
{
    QVector < QString > region;
    if( "{" == listOfCalculations.front() )
    {
        listOfCalculations.pop_front();
        int balans = 1;
        bool flag = true;
        while( flag )
        {


            if(listOfCalculations.front() == "{")
                balans++;
            else if(listOfCalculations.front() == "}" )
                balans--;

            if( ( balans == 0) &&  ( "}" == listOfCalculations.front() ) )
                flag = false;

            region.push_back(listOfCalculations.front() );
            listOfCalculations.pop_front();


        }
    }
    return region;
}
