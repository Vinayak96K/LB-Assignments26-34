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

int Number::Addition(int iNo1,int iNo2)
{
    return iNo1+iNo2;
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

bool Number::IsPerfect(int iNo)
{
    if(iNo<0)
    {
        iNo=-iNo;
    }
    int iSum=0;
    for(int i=1;i<=(iNo/2);i++)
    {
        if((iNo%i)==0)
        {
            iSum=iSum+i;
        }
    }
    if(iSum==iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Number::IsPrime(int iNo)
{
    int i;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    //cout<<iNo<<endl;
    for(i=(iNo/2);i>1;i--)
    {
        if((iNo%i)==0)
        {   
            break;
        }
    }

    if(i!=1)
    {
    //    cout<<i<<endl;
        return false;
    }
    else
    {
    //    cout<<i<<endl;
        return true;
    }
}


int Number::SumDigit(int iNo)
{
    int iSum=0;

    while(iNo!=0)
    {
        iSum=iSum +(iNo%10);
        iNo=iNo/10;
    }
    
    return iSum;
}

Operation::~Operation()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->Next==NULL)
    {
        delete Head;
    }
    else
    {
        PNODE temp=Head;
        while(temp!=NULL)
        {
            Head=temp->Next;
            delete temp;
            temp=Head;
        }
    }
}

void Operation::DisplayPerfect()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        if(IsPerfect((temp->iData)))
        {
            cout<<(temp->iData)<<"\t";
        }
        temp=temp->Next;
    }
    cout<<"\n";

}

void Operation::DisplayPrime()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        if(IsPrime(temp->iData))
        {
        cout<<(temp->iData)<<"\t";
        }
        temp=temp->Next;
    }
    cout<<"\n";
}

void Operation::DisplaySumDigit()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<SumDigit((temp->iData))<<"\t";
        temp=temp->Next;
    }
    cout<<"\n";
}

int Operation::AdditionEven()
{
    int iSum=0;
    PNODE temp=Head;
    while(temp!=NULL)
    {
        if(((temp->iData)&1)==0)
        {
            iSum=Addition(iSum,(temp->iData));
        }
        temp=temp->Next;
    }
    return iSum;
}

int Operation::SecMaximum()
{
    int iMax1;
    int iMax2;
    PNODE temp=NULL;
    if(Head!=NULL)
    {
        temp=Head;
        iMax1=temp->iData;
        iMax2=temp->iData;
    }
    else
    {
        return -1;
    }

    while(temp!=NULL)
    {
        if((iMax1<(temp->iData))&&((temp->iData)>iMax2))
        {
            iMax1=temp->iData;
            iMax2=iMax1;
        }    
        else if((iMax1>(temp->iData))&&((temp->iData)>iMax2))
        {
            iMax2=temp->iData;
        }        
        else if (iMax1==iMax2)
        {
            iMax2=temp->iData;
        }
        
        temp=temp->Next;
    }

    return iMax2;
}