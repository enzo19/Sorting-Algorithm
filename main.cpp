#include <iostream>
#include "timer.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

int quickSort(int s,int n)
{
// fill in
cout<<"aaaa";
}

void merge(int* A, int* B, int l, int m, int r)
{
    int i, j;
    for (i = m + 1; i > l; i--) B[i - 1] = A[i - 1];
    {
        for (j = m; j < r; j++) B[r + m - j] = A[j + 1];
        {
            for (int k = l; k <= r; k++)
            {
                if (B[j] < B[i])
                {
                    A[k] = B[j--];
                }
                else
                {
                    A[k] = B[i++];
                }
            }
        }
    }
}

void mergesort(int* A, int* B, int l, int r,int n)
{
    if(l<r){
        int m=(l+r)/2; //divide
        mergesort(A,B,l,m,n);
        mergesort(A,B,m+1,r,n);
        merge(A,B,l,m,r);
        //if(n<=100)//we only show results of short array
       // {
        /*cout<<"p="<<l<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;*/
       // }
    }
}

int startMergeSort(int* A, int l, int r,int n)
{

    int* B = new int[r - l + 1];
    mergesort(A,B,l,r,n);
    delete [] B;

}

int radixSort(int* A,int n,int largest)
{
    queue<int> bucket[10];
    int divide=1;
    int mod=10;
    for(int i=0;largest/divide>0;i++)
    {
        //cout<<i<<endl;
        for(int j=0;j<n;j++)
        {
            int temp=(A[j]/divide)%mod;
            bucket[temp].push(A[j]);
        }
        for(int k=0,l=0;k<10;k++)
        {
            while(!bucket[k].empty())
            {
                A[l]=bucket[k].front();
                l=l+1;
                bucket[k].pop();
            }
        }
        divide=divide*10;
    }
    /*cout<<"array= ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;*/
}

int main()
{
    cout<<"######################################################"<<endl;
    cout<<"# Comparison of Quick-sort,Radix-sort and Merge-sort #"<<endl;
    cout<<"######################################################"<<endl<<endl;
    cout<<"Please input the size of array: ";
    int n;
    cin>>n;
    int *S=new int[n];
    int *A=new int[n];

    cout<<"Before: ";
    //Initialize random array
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        S[i]=rand(); //limit to 4 digit max? to be modified,maybe
        if(n<=100)//we only show results of short array
        {
            cout<<S[i]<<" ";
        }
    }
    cout<<endl;
    //copy array for reuse
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }
    //Quick-sort



    //Radix-sort
    cout<<"Radix Sort: "<<endl;
    //copy array and get max value
    int largest=S[0];
    for(int i=0;i<n;i++)
    {
         A[i]=S[i];
         if(S[i]>largest)
         {
            largest=S[i];
         }
    }

    system("pause");
    TICK();
    radixSort(A,n,largest);
    TOCK();
    cout<<"Time taken= "<<DURATION()<<endl;
    system("pause");

    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }

    //hvnt done
    //Merge-sort
    cout<<"Merge Sort: "<<endl;
    TICK();
    startMergeSort(A,0,n-1,n);
    TOCK();
    cout<<"Time taken= "<<DURATION()<<endl;
    //delete[] A;

    return 0;
}
