#include<iostream>
using namespace std;

template<class T>
inline T Multiply(T no1, T no2)
{
    return (no1*no2);
}

template<class T>
T MaxN(T no1,T no2,T no3)
{
    if((no1>=no2)&&(no1>=no3))
    {
        return no1;
    }
    else if((no1<=no2)&&(no2>=no3))
    {
        return no2;
    }
    else
    {
        return no3;
    }
}

template<class T>
T AddN(T *arr,int iSize)
{
    if(arr!=NULL)
    {
        if(iSize<0)
        {
            iSize=-iSize;
        }
        int iSum=0;
        for(int i=0;i<iSize;i++)
        {
            iSum=iSum+arr[i];
        }
        return iSum;
    }
}

template<class T>
T Max(T *arr,int iSize)
{
    if(arr!=NULL)
    {
        if((iSize<0)&&(iSize!=0))
        {
            iSize=-iSize;
        }
        T iMax=arr[0];
        for(int i=0;i<iSize;i++)
        {
            if(iMax<arr[i])
            {
                iMax=arr[i];
            }
        }
        return iMax;
    }
}

template<class T>
T Min(T *arr,int iSize)
{
    if((arr!=NULL)&&(iSize!=0))
    {
        if(iSize<0)
        {
            iSize=-iSize;
        }
        T iMin=arr[0];
        for(int i=0;i<iSize;i++)
        {
            if(iMin>arr[i])
            {
                iMin=arr[i];
            }
        }
        return iMin;
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Multiplication of integer is:"<<Multiply<int>(10,15)<<endl;
    cout<<"Multiplication of float is:"<<Multiply<float>(10.5,15.2)<<endl;
    cout<<"Maximum in integer is:"<<MaxN<int>(10,10,5)<<endl;
    cout<<"Maximum in float is:"<<MaxN<float>(10.5,20.0,5.8)<<endl;
    int arr[]={10,20,30,40,50};
    float brr[] = {10.0,3.7,9.8,8.7};
    int iSum = AddN(arr,5);    
    cout<<"Addition of integer array is:"<<iSum<<"\n";
    cout<<"Addition of float array is:"<<AddN(brr,4)<<endl;
    cout<<"Maximum from integer array is:"<<Max(arr,5)<<"\n";
    cout<<"Maximum from float array is:"<<Max(brr,4)<<endl;
    cout<<"Minimum from integer array is:"<<Min(arr,5)<<"\n";
    cout<<"Minimum from float array is:"<<Min(brr,4)<<endl;
    return 0;
}