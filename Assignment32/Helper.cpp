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
        this->Head=node;
    }
    this->Length++;
}

void SinglyLinkedList::InsertLast(int iNo)
{
    if(Head==NULL)
    {
        InsertFirst(iNo);        
    }
    else
    {
        PNODE temp=Head;
        while((temp->Next)!=NULL)
        {
            temp=temp->Next;
        }
        PNODE NewNode=new Node;
        NewNode->iData=iNo;
        NewNode->Next=NULL;
        temp->Next=NewNode;
        this->Length++;
    }    
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

Operation::Operation()
{
    Head=NULL;
    Length=0;
}

Operation::~Operation()
{
    if(Head!=NULL)
    {
        if(Head->Next==NULL)
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
}

Operation& Operation:: operator+(Operation & src)
{
    if(src.Head!=NULL)
    {
        PNODE temp=src.Head;
        while(temp!=NULL)
        {
            this->InsertLast(temp->iData);
            temp=temp->Next;
        }
    }
    return *this;
}


void Operation::ConcatFirstN(Operation &src,int iNo)
{
    if((src.Head!=NULL))
    {    
        PNODE temp=src.Head;
        int i=1;
        if(src.Length<=iNo)
        {
        iNo=src.Length;
        }
        while(i<=iNo)
        {
            InsertLast(temp->iData);
            temp=temp->Next;
            i++;
        }    
    }
}

void Operation::LLCopy(Operation &src)
{
    if(src.Head!=NULL)
    {        
        PNODE temp=src.Head;
        while(temp!=NULL)
        {
            this->InsertLast(temp->iData);
            temp=temp->Next;
        }
    
    }
}

void Operation::LLNCopy(Operation &src,int iNo)
{
    if((src.Head==NULL))
    {
        return;
    }
    PNODE temp=src.Head;
    int i=1;
    if(src.Length<=iNo)
    {
       iNo=src.Length;
    }
    while(i<=iNo)
    {
        InsertLast(temp->iData);
        temp=temp->Next;
        i++;
    }
}

void Operation::ConcatListRange(Operation & src,int iStart,int iEnd)
{
    if(src.Head!=NULL)
    {        
        if(iStart>iEnd)
        {
            int temp=iEnd;
            iEnd=iStart;
            iStart=temp;
        }
        if(src.Length<iEnd)
        {
            iEnd=src.Length;
        }
        PNODE temp=src.Head;
        int i=1;
        while((i<=iEnd)&&(temp!=NULL))          //Updated
        {
            if(i>=iStart)
            {
                InsertLast(temp->iData);
            }
            temp=temp->Next;
            i++;
        }
    }
}