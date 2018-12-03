#include"MyHeader.h"
using namespace MyNamespace;
int main(int argc, char const *argv[])
{
    Operation sObj;
    sObj.DisplayAll();
    sObj.InsertFirst(151);
    sObj.DisplayAll();
    sObj.InsertFirst(121);
    sObj.DisplayAll();
    sObj.InsertFirst(111);
    sObj.DisplayAll();
    sObj.InsertFirst(181);
    sObj.DisplayAll();
    sObj.InsertFirst(21);
    sObj.DisplayAll();
    sObj.InsertFirst(11);
    sObj.DisplayAll();
    int iRet=sObj.SearchFirst(121);
    if(iRet>=0)
    {
        cout<<"Element found at location:"<<iRet<<endl;
    }
    else
    {
        cout<<"Element not found!\n";
    }

    cout<<"Last location of occurance is:"<<sObj.SearchLast(121)<<endl;
    cout<<"Maximum element="<<sObj.Maximum()<<endl;
    cout<<"Maximum element="<<sObj.Minimum()<<endl;
    cout<<"Addition="<<sObj.Addition(NULL)<<endl;
    return 0;
}
