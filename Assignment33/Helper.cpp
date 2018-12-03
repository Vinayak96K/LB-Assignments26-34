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

///////////////////////////////////////////////Copy Even/////////////////////////////////////////////////////
void Operation::LLCopyEX(Operation &src)
{
    if(src.Head!=NULL)
    {        
        PNODE temp=src.Head;
        while(temp!=NULL)
        {
            if(((temp->iData)&(1))==0)
            {
            this->InsertLast(temp->iData);
            }
            temp=temp->Next;
        }    
    }
}//

///////////////////////////////////////////////Sub Linked List/////////////////////////////////////////////////////
int Operation::SubList(Operation &src)
{
    if((src.Head!=NULL)&&(this->Head!=NULL))
    {
        int i=0;
        PNODE temp1=this->Head;
        PNODE temp2=src.Head;
        int Index=1;
        while(temp1!=NULL)
        {
            if((temp1->iData)==(temp2->iData))
            {
                while((temp2!=NULL)&&(temp1!=NULL))
                {
                    if(((temp1->iData)==(temp2->iData)))
                    {
                        temp1=temp1->Next;
                        temp2=temp2->Next;
                        i++;
                    }
                    else
                    {
                        Index=Index+(i-1);
                        i=0;
                        temp2=src.Head;
                        break;
                    }
                }
            }
            else
            {
                i=0;
                temp1=temp1->Next;
            }
            if(i==(src.Length))
            {
                break;
            }
            Index++;
        }
        if(i==(src.Length))
        {
            return (Index);
        }
        else
        {
            return -1;
        }        
    }
}//

///////////////////////////////////////////Copy Ascending////////////////////////////////////////////////
void Operation::CopyAsen(Operation &src)
{
    if(src.Head!=NULL)
    {
        PNODE temp1=src.Head;
        PNODE temp2=this->Head;
        while(temp1!=NULL)
        {
            if(temp1!=src.Head)
            {                
                while(temp2!=NULL)
                {
                    if(temp2->Next!=NULL)
                    {
                        if(((temp1->iData)<=(temp2->iData)))
                        {
                            InsertFirst(temp1->iData);
                            break;
                        }
                        else if(((temp1->iData)>(temp2->iData))&&((temp1->iData)>(temp2->Next->iData)))
                        {
                            while((temp2->Next!=NULL)&&((temp1->iData)>(temp2->Next->iData)))
                            {
                                temp2=temp2->Next;
                            }
                            InsertAt(temp2,temp1->iData);
                            break;
                        }
                        else if(((temp1->iData)>(temp2->iData))&&((temp1->iData)<=(temp2->Next->iData)))
                        {
                            InsertAt(temp2,temp1->iData);
                            break;
                        }
                    }
                    else
                    {
                        if(temp1->iData>=temp2->iData)
                        {
                            this->InsertAt(temp2,temp1->iData);
                            break;
                        }
                        else
                        {
                            this->InsertFirst(temp1->iData);
                            break;
                        }
                    }
                }
                
            }
            else
            {
                this->InsertFirst(temp1->iData);
            }
            temp1=temp1->Next;            
            temp2=this->Head;
            //this->DisplayAll();
        }
    }
}//

////////////////////////////////////////////////Reverse Linked List///////////////////////////////////////////////////////////////
void Operation::ListReverse()
{
    TraversalSwap(this->Head);
}

void Operation::TraversalSwap(PNODE src)
{
    if((this->Head!=NULL)&&(this->Head->Next!=NULL))
    {
        static PNODE temp1=this->Head;
        static int i=1;
        static int j=this->Length;
        if(src->Next!=NULL)
        {
            TraversalSwap(src->Next);
        }
        if(i>=j)
        {
            return;
        }
        else
        {
            int iTemp=src->iData;
            src->iData=temp1->iData;
            temp1->iData=iTemp;
            i++;
            j--;
            temp1=temp1->Next;
        }
    }
}
//


void Operation::createLoop()
{
    if(this->Head!=NULL)
    {
        PNODE temp=this->Head;
        
        while(temp->Next)
        {
            temp=temp->Next;
        }
        if(this->Head->Next==NULL)
        {
        temp->Next=this->Head;
        }
        else
        {
            temp->Next=this->Head->Next;
        }
    }
}

BOOL Operation::chkLoop()
{
    PNODE temp=this->Head;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->Next;
        if(i>this->Length)
        {
            break;
        }
    }
    if((temp!=NULL)&&(i>this->Length))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}