#include"MyHeader.h"

int Count(int iNo)
{
    static int iCnt=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    if(iNo!=0)
    {
        iCnt++;
        iNo=iNo/10;
        Count(iNo);
    }
    return iCnt;
}

int AddR(int *arr,int iSize)
{
    static int i=0;
    static int Sum=0;
    if(iSize<0)
    {
        iSize=-iSize;
    }
    if(i<iSize)
    {
        Sum=Sum+arr[i++];
        AddR(arr,iSize);
    }
    return Sum;
}

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE NewNode=(PNODE) malloc(sizeof(NODE));
    NewNode->data=iNo;
    NewNode->next=NULL;

    if(*Head==NULL)
    {
        *Head=NewNode;
    }
    else
    {
        NewNode->next=*Head;
        *Head=NewNode;
    }
}


void DisplayLL(PNODE Head)
{
    if(Head!=NULL)
    {
        printf("|%d|->",Head->data);
        DisplayLL(Head->next);
    }
}

void StrRevDisplayR(char *str)
{
    if(*str!='\0')
    {
        StrRevDisplayR(str+1);
        printf("%c\t",*str);
    }
}

void FactorR(int iNo)
{
    static int i=1;
    if(i<=(iNo/2))
    {
        if(iNo%i==0)
        {
            printf("%d\t",i);
        }
        FactorR(iNo);
    }
}