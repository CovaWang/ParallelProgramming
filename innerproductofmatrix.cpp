#include <iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

CONST INT Msize=10001;

DOUBLE matrix[Msizes][Msize];
double colmatrix[Msize];
double results[Msize];//结果


void initmatrix()//初始化矩阵
{
	for (int i = 0;i < Msize;i++)
	{
		for (int j = 0;j < Msize;j++)
		{
			matrix[i][j] = i + j;
		}
		colmatrix[i] = i + 1;
		results[i] = 0.0;
	}

}
int main()
{
	long long head, tail, freq;
	long double totaltime=0.0;
	initmatrix();

    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    for(int k=0;k<10;k++)
    {
        //start time
        QueryPerformanceCounter((LARGE_INTEGER*)&head);


        //trivial
        /*
        for (int i = 0;i < Msize;i++)
        {
            for (int j = 0;j < Msize;j++)
            {
                results[i] += matrix[j][i] * colmatrix[j];
            }
        }
        */
        //cacheOptimize，与行主存储匹配
        for (int j = 0;j < Msize;j++)
        {
            for (int i = 0;i < Msize;i++)
            {
                results[i] += matrix[j][i] * colmatrix[j];
            }
        }

        //end time
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        tmp+=(tail-head)*1000.0/freq;
    }

    cout<<"用时为:"<<tmp/10<<"ms"<<endl;
    return 0;
}
