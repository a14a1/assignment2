#include "BigDecimaClassl.h"


using namespace std;
//Constractor
BigDecimalInt::BigDecimalInt()
{}
//setter function
//it takes
//it setts the initial value for the string
void BigDecimalInt::SetBigDecimalInt(string S)
{
    decStr = S;
}
void BigDecimalInt::SetBigDecimalInt(string S, int Size)
{
    decStr = S;
    decint = Size;
}
string BigDecimalInt::GetBigDecimalInt ()
{
    return decStr;
}
int BigDecimalInt::Size()
{
    int StringSize = decStr.length();
    return StringSize;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    BigDecimalInt returnDec;
    int firstNum , secondNum , resultNum , anotherNum, c = 0;
    int len =  anotherDec.decStr.length(), len2 = this->decStr.length();
    if (len != len2)
    {
        for (int i = 0; i < (len2 - len); i++)
            anotherDec.decStr.insert(i,"0");
    }
    char * P = new char[len2];
    for (int x = len2 - 1 ; x >= 0; x--)
    {
        if ((anotherNum == (firstNum + 10)) || (c == 1))
        {
            firstNum = this->decStr[x] - '0' ;
            anotherNum = 0;
            if (c == 1)
            {
                 c = 0;
            }
            if (firstNum != 0)
            {
               firstNum -= 1;
            }
            else
            {
                firstNum += 9;
                c ++;
            }
        }
        else
        {
            firstNum =  this->decStr[x] - '0';
        }
        secondNum =  anotherDec.decStr[x] - '0';
        if(firstNum >= secondNum)
        {
            resultNum = firstNum - secondNum;
            P[x] = (resultNum  + '0');
        }
        else
        {
            anotherNum = firstNum + 10;
            resultNum = anotherNum - secondNum;
            P[x] = (resultNum  + '0');
        }
    }
    string g = P;
    returnDec.SetBigDecimalInt(g, len2);
    return returnDec;
}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec)
{
    BigDecimalInt returnDec;
    int firstNum , secondNum , resultNum , anotherNum, c = 0;
    int len =  anotherDec.decStr.length(), len2 = this->decStr.length();
    if (len != len2)
    {
        for (int i = 0; i < (len2 - len); i++)
            anotherDec.decStr.insert(i,"0");
    }
    char * P = new char[len2];
    for(int x = len2 - 1 ; x >= 0; x--)
    {
        if (c == 1)
        {
            c = 0;
            firstNum = this->decStr[x] - '0' ;
            firstNum = firstNum + 1 ;
        }
        else
            firstNum = this->decStr[x] - '0' ;


        secondNum =  anotherDec.decStr[x] - '0';
        resultNum = firstNum + secondNum;
        if (resultNum > 9)
        {
            resultNum = resultNum % 10;
            c ++;
        }
        P [x] = resultNum + '0';
    }
    string g = P;
    returnDec.SetBigDecimalInt(g, len2);
    return returnDec;
}
ostream& operator<< (ostream& out, BigDecimalInt anotherDec)
{
    int len =  anotherDec.decint,counter = 0 ;
     for(int i = 0; i < len; i++)
    {
        if (anotherDec.decStr [i] == '0')
            counter ++;
        else
            break;
    }
    if (counter == len)
        out << 0;
    else
    {
        for (int j = counter ; j <= len; j++)
            out << anotherDec.decStr[j];
    }
    return out;
}

