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

void SinglyLinkedList::InsertAt(PNODE location,int iNo)
{
    if(location==NULL)
    {
        InsertLast(iNo);
    }
    else if(location->Next==NULL)
    {
        PNODE newNode=new Node;
        newNode->iData=iNo;
        newNode->Next=NULL;
        location->Next=newNode;
        this->Length++;
    }
    else
    {
        PNODE newNode=new Node;
        newNode->iData=iNo;
        newNode->Next=NULL;
        newNode->Next=location->Next;
        location->Next=newNode;
        this->Length++;
    }
}

void SinglyLinkedList::InsertBefore(PNODE TempHead,PNODE location,int iNo)
{
    if((TempHead!=NULL)&&(location!=NULL))
    {
        if(TempHead==location)
        {
            PNODE newNode;
            newNode->iData=iNo;
            newNode->Next=location;
            this->Head=newNode;
        }
        else
        {     
            while((TempHead!=NULL)&&(TempHead->Next!=location))
            {
                TempHead=TempHead->Next;
            }
            if(TempHead!=NULL)
            {
                PNODE newNode;
                newNode->iData=iNo;
                newNode->Next=TempHead->Next;
                TempHead->Next=newNode;
            }
        }
        
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
        if(this->Head->Next==NULL)
        {
            delete this->Head;
        }
        else
        {
            PNODE temp=Head;
            int i=0;
            while(temp!=NULL)
            {
                this->Head=temp->Next;
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

//////////////////////////////////////////////////////Swap nodes////////////////////////////////////////////////////////////
void Operation::Swap()
{
    if(this->Head!=NULL)
    {
        PNODE temp=this->Head;
        while(temp->Next!=NULL)
        {
            int iTemp=temp->iData;
            temp->iData=temp->Next->iData;
            temp->Next->iData=iTemp;
            temp=temp->Next->Next;
        }
    }
}//

///////////////////////////////////////////////////Insert Linked list At Position////////////////////////////////////////////////
void Operation::InsertLinkedListAt(Operation &src,int iPos)
{
    if((src.Head!=NULL)&&(src.Head!=this->Head))
    {
        PNODE temp1=this->Head;
        PNODE temp2=src.Head;
        PNODE temp=NULL;
        if(iPos<0)
        {
            iPos=-iPos;
        }
        if(iPos>this->Length)
        {
                iPos=this->Length+1;
        }
        if((this->Head==NULL)||(iPos==1))
        {
            temp=this->Head;
            this->Head=src.Head;
            while(temp2->Next!=NULL)
            {
                temp2=temp2->Next;
            }
            temp2->Next=temp;
        }
        else if(this->Head->Next!=NULL)
        {
            int i=1;
            while((i<(iPos-1))&&(temp1!=NULL))
            {
                temp1=temp1->Next;
                i++;
            }
            temp=temp1->Next;
            temp1->Next=src.Head;
            while(temp1->Next!=NULL)
            {
                temp1=temp1->Next;
            }
            temp1->Next=temp;
        }
        else
        {
            this->Head->Next=src.Head;
        }
        this->Length += src.Length;
        src.Length=this->Length-iPos;
    }
}//

////////////////////////////////////////////////////////////Check List Intersects//////////////////////////////////////////////////////
BOOL Operation::ListIntersect(Operation &src)
{
    if((src.Head!=NULL)&&(src.Head!=this->Head))
    {
        PNODE temp1=this->Head;
        PNODE temp2=src.Head;
        while(temp1->Next!=NULL)
        {
            temp2=src.Head;
            while(temp2!=NULL)
            {
                if(temp1->Next==temp2)
                {
                    break;
                }
                else
                {
                    temp2=temp2->Next;
                }
            }
            if((temp1->Next==temp2))
            {
                break;
            }
            else
            {
                temp1=temp1->Next;
            }
        }
        if(temp1->Next!=NULL)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}//

///////////////////////////////////////////////////////////Check List is pallindrome or not//////////////////////////////////////////////////////
BOOL Operation::ListPallindrome()
{
    BOOL bRet=FALSE;
    if(this->Head!=NULL)
    {
        bRet =this->TraversalCheck(this->Head);
    }
}

BOOL Operation::TraversalCheck(PNODE src)
{
    BOOL bRet=TRUE;
    if((this->Head!=NULL)&&(this->Head->Next!=NULL))
    {
        static PNODE temp1=this->Head;
        static int i=1;
        static int j=this->Length;
        if(src!=NULL)
        {
            bRet=TraversalCheck(src->Next);
            if(bRet==0)
            {
                bRet=FALSE;
            }
            else if(i<j)
            {
                if(temp1->iData==src->iData)
                {
                    bRet=TRUE;
                }
                else
                {
                    bRet=FALSE;
                }
            }
            i++;
            j--;
            temp1=temp1->Next;
        }
    }
    return bRet;

}

/////////////////////////////////////////////////////////////Compare linked list////////////////////////////////////////////////////////
BOOL Operation::CmpList(Operation &src)
{
    BOOL bRet=FALSE;
    if((this->Head!=NULL)&&(src.Head!=NULL))
    {
        if(this->Length==src.Length)
        {
            PNODE temp1=this->Head;
            PNODE temp2=src.Head;
            while((temp1!=NULL)&&(temp2!=NULL))
            {
                if(temp1->iData!=temp2->iData)
                {
                    bRet=FALSE;
                    break;
                }
                else
                {
                    bRet=TRUE;
                    temp1=temp1->Next;
                    temp2=temp2->Next;
                }
            }
        }
        else
        {
            bRet=FALSE;
        }
    }
    return bRet;
}