#include"MyHeader.h"
using namespace MyNamespace;
int main(int argc, char const *argv[])
{
    Operation sObj1,sObj2,sObj3,sObj4,sObj5;
    sObj1.InsertFirst(70);
    sObj1.InsertFirst(80);
    sObj1.InsertFirst(10);
    sObj1.InsertFirst(73);
    sObj1.DisplayAll();
    sObj2.InsertFirst(21);
    sObj2.InsertFirst(70);
    sObj2.InsertFirst(80);
    sObj2.InsertFirst(12);
    sObj2.InsertFirst(70);
    sObj2.InsertFirst(80);
    sObj2.InsertFirst(10);
    sObj2.InsertFirst(73);
    sObj2.InsertFirst(110);
    sObj2.DisplayAll();
    /*sObj2.LLCopyEX(sObj1);
    sObj2.DisplayAll();*/
    int iRet=sObj2.SubList(sObj1);
    if(iRet==(-1))
    {
        cout<<"It is not a sub-Linked list!\n";
    }
    else
    {
        cout<<"Sublist starts form index:"<<iRet<<endl;
    }
    cout<<"LinkedList after copying in Ascending order:\n";
    sObj3.CopyAsen(sObj2);
    sObj3.DisplayAll();
    sObj3.ListReverse();
    sObj3.DisplayAll();
    //sObj1.createLoop();
    if(sObj1.chkLoop())
    {
        cout<<"Linked List contains loop\n";
    }
    else
    {
        cout<<"Linked List does not contains loop\n";
    }
    
    return 0;
}
