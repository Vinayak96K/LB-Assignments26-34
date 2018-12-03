#include"MyHeader.h"

int main(int argc, char const *argv[])
{
    bool Running = true;
    int iArr[9]={10,20,30,10,30,40,10,40,10};
    char cArr[12]="Hello World";
    float fArr[5]={10.20,15.14,12.14,144.102,12.14};
    while(Running)
    {
        cout<<"1. Question 1\n";
        cout<<"2. Question 2\n";
        cout<<"3. Question 3\n";
        cout<<"4. Question 4\n";
        cout<<"5. Question 5\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice:\t";
        int iChoice=0;
        cin>>iChoice;

        switch(iChoice)
        {
            case 0:
                Running=false;
                break;
                
            case 1:
                Display<int>(15,5);
                Display<char>('M',5);
                break;

            case 2:
                cout<<"Frequency of 10 is:"<<Frequency<int>(iArr,9,10)<<endl;
                cout<<"Frequency of l is:"<<Frequency<char>(cArr,12,'l')<<endl;
                cout<<"Frequency of 12.14 is:"<<Frequency<float>(fArr,5,12.14)<<endl;
                break;

            case 3:
                cout<<"First occurence of 11 is:"<<SearchFirst<int>(iArr,9,40)<<endl;
                cout<<"First occurence of l is:"<<SearchFirst<char>(cArr,12,'l')<<endl;
                cout<<"First occurence of 12.14 is:"<<SearchFirst<float>(fArr,5,12.14)<<endl;
                break;

            case 4:
                cout<<"Last occurence of 40 is:"<<SearchLast<int>(iArr,9,40)<<endl;
                cout<<"Last occurence of l is:"<<SearchLast<char>(cArr,12,'l')<<endl;
                cout<<"Last occurence of 12.14 is:"<<SearchLast<float>(fArr,5,12.14)<<endl;
                break;

            case 5:
                Reverse<int>(iArr,9);
                cout<<"Integer array after reverse:";
                for(int i=0;i<9;i++)
                {
                    cout<<iArr[i]<<"\t";
                }
                cout<<"\nFloat array after reverse:";
                Reverse<float>(fArr,5);
                for(int i=0;i<5;i++)
                {
                    cout<<fArr[i]<<"\t";
                }
                cout<<"\nCharacter array after reverse:";
                Reverse<char>(cArr,12);
                for(int i=0;i<12;i++)
                {
                    cout<<cArr[i]<<"\t";
                }
                cout<<"\n";
                break;

            default:
                cout<<"Invalid choice!\n";
                break;
        }
    }
    return 0;
}
