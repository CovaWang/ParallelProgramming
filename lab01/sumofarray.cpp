#include <iostream>
#include<windows.h>
using namespace std;
const int N=10001;//size
int a[N];

void initarray(int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
}

void trivial(int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
}

void multipath(int n)
{
    int sum1=0,sum2=0;
    for(int i=0;i<n;i+=2)
    {
        sum1+=a[i];
        sum2+=a[i+1];
    }
    sum1+=sum2;
}

void recursion(int n)
{
    if(n==1)
    {
        return;
    }
    else
    {
        for(int i=0;i<n/2;i++)
        {
            a[i]+=a[n-i-1];
        }
        n=n/2;
        recursion(n);
    }
}

void doubleloop(int n)
{
    for(int m=n;m>1;m/=2)
    {
        for(int i=0;i<m/2;i++)
        {
            a[i]=a[i*2]+a[i*2+1];
        }
    }
}

int main()
{
    long long head,tail,freq; //timers
    long double totaltime=0.0;
    initarray(N);

    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    for(int k=0;k<100;k++)
    {
        //start time
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        //trivial(N);
        //multipath(N);
        //recursion(N);
        doubleloop(N);

        //end time
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        totaltime+=(tail-head)*1000.0/freq;
    }

    cout<<"ÓÃÊ±:"<<totaltime/100<<"ms"<<endl;
    return 0;
}
