#include"MyHeader.h"
using namespace MyNamespace;
struct Node
{
    int iData;
    PNODE Next;
};

SinglyLinkedList::SinglyLinkedList()
{
    Head=NULL;
    Length=0;
}

void SinglyLinkedList::InsertFirst(int iNo)
{
    PNODE node= new Node;
    node->iData=iNo;
    node->Next=NULL;

    if(Head==NULL)
    {
        Head=node;
    }
    else
    {
        node->Next=Head;
        Head=node;
    }
    Length++;
}

void SinglyLinkedList::DisplayAll()
{
    PNODE nTemp=Head;
    while(nTemp!=NULL)
    {
        cout<<"|"<<nTemp->iData<<"|->";
        nTemp=nTemp->Next;
    }
    cout<<"|NULL|\n";
}

int Number::Maximum(int iNo1,int iNo2)
{
    if(iNo1>iNo2)
    {
        return iNo1;
    }
    else
    {
        return iNo2;
    }
}

int Number::Minimum(int iNo1,int iNo2)
{
    if(iNo1<iNo2)
    {
        return iNo1;
    }
    else
    {
        return iNo2;
    }
}

int Operation::SearchFirst(int iNo)
{
    if(Head==NULL)
    {
        return -1;
    }
    else
    {
        PNODE nTemp=Head;
        int i=-1;

        while(nTemp!=NULL)
        {
            i++;
            if(nTemp->iData==iNo)
            {
                break;
            }
            nTemp=nTemp->Next;
        }        

        if(nTemp!=NULL)
        {
            return (i+1);
        }
        else
        {
            return -1;
        }
    }
}

int Operation::SearchLast(int iNo)
{
    if(Head==NULL)
    {
        return -1;
    }
    int iRet=Search(Head,iNo);
    return iRet;
}

int Operation::Search(PNODE node,int iNo)
{
    static int Index=0;
    Index++;
    int iRet=0;
    if(node->Next!=NULL)
    {
        iRet=Search(node->Next,iNo);
        Index--;
    }
    if(iRet==0)
    {
        if(node->iData==iNo)
        {
            return Index;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return iRet;
    }
}

int Operation::Maximum()
{
    int iNo=-1;
    if(Head!=NULL)
    {
        PNODE nTemp=Head;
        iNo=nTemp->iData;
        while(nTemp!=NULL)
        {
            int temp=nTemp->iData;
            iNo=Number::Maximum(iNo,temp);
            nTemp=nTemp->Next;
        }
    }
    return iNo;
}

int Operation::Minimum()
{
    int iNo=-1;
    if(Head!=NULL)
    {        
        PNODE nTemp=Head;
        iNo=nTemp->iData;
        while(nTemp!=NULL)
        {
            int temp=nTemp->iData;
            iNo=Number::Minimum(iNo,temp);
            nTemp=nTemp->Next;
        }
    }
    return iNo;
}

int Operation::Addition(PNODE hTemp)
{
    static int iAdd=0;
    if(Head==NULL)
    {
        return 0;
    }
    if(hTemp==NULL)
    {
        hTemp=Head;
    }

    if(hTemp->Next!=NULL)
    {
        iAdd=Addition(hTemp->Next);
        iAdd=iAdd+hTemp->iData;
    }
    else
    {
        iAdd=iAdd+hTemp->iData;
    }

    return iAdd;
}
