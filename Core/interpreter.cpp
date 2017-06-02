#include "parser.h"

#include <math.h>


void Parser::fillingInTheListOfCalculations()
{
    while(!tokinList.empty())
    {
        if(tokinList.front() == ";")
        {
            while( (!stack.empty()) && ("{" != stack.back()) )
            {
                listOfCalculations.push_back(stack.back());
                stack.pop_back();
            }
            tokinList.pop_front();
        }
        else if(!isOperation(tokinList.front()))
        {
            listOfCalculations.push_back(tokinList.front());
            tokinList.pop_front();
        }
        else if((tokinList.front() == ")" || tokinList.front() == "("))
        {
            if(tokinList.front() == "(" )
            {
                stack.push_back(tokinList.front());
                tokinList.pop_front();
            }
            else
            {
                tokinList.pop_front();
                while("(" != stack.back() )
                {
                    listOfCalculations.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            }
        }
        else if( (tokinList.front() == "{" || tokinList.front() == "}") )
        {
            if(tokinList.front() == "{")
            {
                listOfCalculations.push_back(stack.back());
                stack.pop_back();
                stack.push_back(tokinList.front());
                listOfCalculations.push_back(tokinList.front());
                tokinList.pop_front();
            }
            else
            {
                while("{" != stack.back() )
                {
                    listOfCalculations.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
                listOfCalculations.push_back(tokinList.front());
                tokinList.pop_front();
            }
        }
        else
        {
            if(!stack.empty())
            {
                if( priorityOfOperations(tokinList.front()) > priorityOfOperations( stack.back() ) )
                {
                    stack.push_back(tokinList.front());
                    tokinList.pop_front();
                }
                else
                {
                    while(priorityOfOperations(tokinList.front()) <= priorityOfOperations( stack.back() ) )
                    {
                        listOfCalculations.push_back(stack.back());
                        stack.pop_back();
                    }
                    stack.push_back(tokinList.front());
                    tokinList.pop_front();
                }
            }
            else
            {
                stack.push_back(tokinList.front());
                tokinList.pop_front();

            }
        }
    }
}





bool Parser::isOperation(QString tokin)
{
    if(tokin == "print" || tokin == "repeat")
        return true;
    else if( tokin == "if" || tokin == "{" || tokin == "}" || tokin == "else")
        return true;
    else if( tokin == "(" ||  tokin == ")"  || tokin == "true" || tokin == "flase" )
        return true;
    else if( tokin == "=")
        return true;
    else if(tokin == "<" || tokin == ">" || tokin == "==" || tokin == "!=" || tokin == ">=" || tokin == "=<" )
        return true;
    else if( tokin == "+")
        return true;
    else if( tokin == "-")
        return true;
    else if(  tokin == "*")
        return true;
    else if( tokin == "/" )
        return true;
    else if( tokin == "^" || tokin == "sqrt" )
        return true;
    else
        return false;


}

int Parser::priorityOfOperations(QString tokin)
{
    if(tokin == "print")
        return 0;
    else if( tokin == "if" || tokin == "repeat" )
        return 0;
    else if( tokin == "{" || tokin == "}")
        return -1;
    else if( tokin == "(" ||  tokin == ")"  || tokin == "true" || tokin == "flase")
        return -2;
    else if( tokin == "=")
        return 1;
    else if(tokin == "<" || tokin == ">" || tokin == "==" || tokin == "!=" || tokin == ">=" || tokin == "=<" )
        return 2;
    else if( tokin == "+")
        return 3;
    else if( tokin == "-")
        return 3;
    else if(  tokin == "*")
        return 4;
    else if( tokin == "/" )
        return 4;
    else if( tokin == "else" )
        return 5;
    else if(tokin == "^" || tokin =="sqrt")
        return 6;
    else
        return 0;
}
