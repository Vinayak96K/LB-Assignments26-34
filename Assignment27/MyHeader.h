#include<iostream>
using namespace std;

template<class T> void Display(T value,int iSize)
{
    if(iSize<0)
    {
        iSize=-iSize;
    }
    for(int i=0;i<iSize;i++)
    {
        cout<<value<<"\t";
    }
    cout<<"\n";
}

template<class T> int Frequency(T *arr,int iSize,T value)
{
    if(arr!=NULL)
    {
        int iCnt=0;
        if(iSize<0)
        {
            iSize=-iSize;
        }
        for(int i=0;i<iSize;i++)
        {
            if(arr[i]==value)
            {
                iCnt++;
            }
        }
        return iCnt;
    }
    else
    {
        return -1;
    }
}

template<class T> int SearchFirst(T *arr,int iSize,T value)
{
    if(arr!=NULL)
    {
        int i;
        if(iSize<0)
        {
            iSize=-iSize;
        }
        for(i=0;i<iSize;i++)
        {
            if(arr[i]==value)
            {
                break;
            }
        }
        if(i<iSize)
        {
            return i;
        }
        else
        {
            cout<<"Element not found! errCode:";
            return -1;
        }
        
    }
    else
    {
        cout<<"Element not found! errCode:";
        return -2;
    }
}

template<class T> int SearchLast(T *arr,int iSize,T value)
{
    if(arr!=NULL)
    {
        int i;
        if(iSize<0)
        {
            iSize=-iSize;
        }
        for(i=(iSize-1);i>0;i--)
        {
            if(arr[i]==value)
            {
                break;
            }
        }
        if(i>0)
        {
            return i;
        }
        else
        {
            cout<<"Element not found! errCode:";
            return -1;
        }
        
    }
    else
    {
        cout<<"Element not found! errCode:";
        return -2;
    }
}

template<class T> void Reverse(T *arr,int iSize)
{
    if(arr!=NULL)
    {
        int i,j;
        T temp;
        if(iSize<0)
        {
            iSize=-iSize;
        }
        for(i=0,j=(iSize-1);i<j;i++,j--)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;    
        }
    }
}