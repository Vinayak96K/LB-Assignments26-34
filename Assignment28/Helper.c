#include"MyHeader.h"

void DisplayCharR(char ch)
{
    static int i=1;
    if(i<=4)
    {
        i++;
        DisplayCharR(ch);
    }
    printf("%c\t",ch);
}

void DisplayIntR(int iNo)
{
    static int i=1;
    if(i<=4)
    {
        i++;
        DisplayIntR(iNo);
    }
    printf("%d\t",iNo);
}

int FactR(int iNo)
{
    if(iNo<=0)
    {
        return -1;
    }
    static int iAns=1;
    if(iNo!=1)
    {
        iAns=iAns*iNo;
        iNo--;
        FactR(iNo);
    }
    return iAns;
}

void StrDisplayR(char *str)
{
    if(*str!='\0')
    {
        printf("%c\t",*str++);
        StrDisplayR(str);
    }
}

int StrLenR(char *str)
{
    static int iLen=0;
    if(*str!='\0')
    {
        iLen++;
        StrLenR(++str);
    }
    return iLen;

}