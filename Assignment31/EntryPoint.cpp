#include"MyHeader.h"
using namespace MyNamespace;
int main(int argc, char const *argv[])
{
    Operation sObj;
    sObj.DisplayAll();
    sObj.InsertFirst(151);
    sObj.DisplayAll();
    sObj.InsertFirst(6);
    sObj.DisplayAll();
    sObj.InsertFirst(110);
    sObj.DisplayAll();
    sObj.InsertFirst(184);
    sObj.DisplayAll();
    sObj.InsertFirst(28);
    sObj.DisplayAll();
    sObj.InsertFirst(11);
    sObj.DisplayAll();
    cout<<"\nPerfect Numbers:\t";
    sObj.DisplayPerfect();
    cout<<"Prime Numbers:\t\t";
    sObj.DisplayPrime();
    cout<<"Sum of digits:\t\t";
    sObj.DisplaySumDigit();
    cout<<"Second Maximum:\t\t"<<sObj.SecMaximum()<<"\n";
    cout<<"Even Addition:\t\t"<<sObj.AdditionEven()<<"\n";
}
