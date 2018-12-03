#include"MyHeader.h"
using namespace MyNamespace;
int main(int argc, char const *argv[])
{
    Operation sObj1,sObj2,sObj3,sObj4,sObj5;
    sObj1.InsertFirst(70);
    sObj1.InsertFirst(30);
    sObj1.InsertFirst(20);
    sObj1.InsertFirst(15);
    sObj1.DisplayAll();
    sObj2.InsertFirst(40);
    sObj2.InsertFirst(30);
    sObj2.InsertFirst(20);
    sObj2.InsertFirst(10);
    sObj2.DisplayAll();
    sObj2=sObj2+sObj1;
    sObj2.DisplayAll();
    sObj1.DisplayAll();
    sObj2.ConcatFirstN(sObj2,3);
    sObj2.DisplayAll();
    sObj3.LLCopy(sObj1);
    sObj3.DisplayAll();
    sObj4.LLNCopy(sObj2,3);
    sObj4.DisplayAll();
    sObj2.ConcatListRange(sObj2,2,5);
    sObj2.DisplayAll();

    return 0;
}
