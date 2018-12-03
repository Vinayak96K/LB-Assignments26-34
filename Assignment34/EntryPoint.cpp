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
    sObj2.Swap();
    sObj2.DisplayAll();
    sObj2.InsertLinkedListAt(sObj1,4);
    sObj2.DisplayAll();
    sObj1.DisplayAll();
    
    BOOL bRet=sObj2.ListIntersect(sObj1);
    if(bRet==1)
    {
        cout<<"Intersects.\n";
    }
    else
    {
        cout<<"Does not intersects.\n";
    }

    sObj3.InsertLast(15);
    sObj3.InsertLast(50);
    sObj3.InsertLast(40);
    sObj3.InsertLast(50);
    sObj3.InsertLast(15);
    sObj3.DisplayAll();
    if(sObj3.ListPallindrome())
    {
        cout<<"List is pallindrome!\n";
    }
    else
    {
        cout<<"List is not pallindrome!\n";
    }

    sObj4.InsertLast(15);
    sObj4.InsertLast(50);
    sObj4.InsertLast(40);
    sObj4.InsertLast(50);
    sObj4.InsertLast(15);
    sObj4.DisplayAll();
    if(sObj3.CmpList(sObj2))
    {
        cout<<"Linked Lists are equal!\n";
    }
    else
    {
        cout<<"Linked Lists are not equal!\n";
    }

    return 0;
}
