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

void trivial(int n)//平凡链式算法：将给定元素依次累加
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
}

void multipath(int n)//多路链式实现
{
    int sum1=0,sum2=0;
    for(int i=0;i<n;i+=2)//只需要实现n/2次循环
    {
        sum1+=a[i];
        sum2+=a[i+1];
    }
    sum1+=sum2;
}

void recursion(int n)//递归算法实现
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
        recursion(n);//尾递归
    }
}

void doubleloop(int n)//双重循环
{
    for(int m=n;m>1;m/=2)
    {
        for(int i=0;i<m/2;i++)
        {
            a[i]=a[i*2]+a[i*2+1];
        }
    }
    //a[0]为最终结果
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
        //trivial(N);//平凡链式相加
        //multipath(N);//多链路
        //recursion(N);//递归
        doubleloop(N);//双重循环

        //end time
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        totaltime+=(tail-head)*1000.0/freq;
    }

    cout<<"用时:"<<totaltime/100<<"ms"<<endl;
    return 0;
}
