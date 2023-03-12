#include <iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
CONST INT Msize=10001;
DOUBLE matrix[Msizes][Msize];
double colmatrix[Msize];
double result[Msize];


void initmatrix()
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
    for(int k=0;k<100;k++)
    {
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
        //cacheOptimize
        for (int j = 0;j < Msize;j++)
        {
            for (int i = 0;i < Msize;i++)
            {
                results[i] += matrix[j][i] * colmatrix[j];
            }
        }

        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        totaltime+=(tail-head)*1000.0/freq;
    }

    cout<<"ÓÃÊ±:"<<totaltime/100<<"ms"<<endl;
    return 0;
}
