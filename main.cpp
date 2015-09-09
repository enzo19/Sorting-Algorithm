#include <iostream>
#include "timer.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int quickSort(int s,int n)
{
// fill in
}

void merge(int* A, int* B, int l, int m, int r)
{
int i, j;
for (i = m + 1; i > l; i--) B[i - 1] = A[i - 1];
    for (j = m; j < r; j++) B[r + m - j] = A[j + 1];
        for (int k = l; k <= r; k++)
            if (B[j] < B[i])
                A[k] = B[j--];
            else
                A[k] = B[i++];
}

void mergesort(int* A, int* B, int l, int r,int n)
{
    if(l<r){
        int m=(l+r)/2; //divide
        mergesort(A,B,l,m,n);
        mergesort(A,B,m+1,r,n);
        merge(A,B,l,m,r);
        if(n<=100)//we only show results of short array
        {
        cout<<"p="<<l<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }
    }
}

int startMergeSort(int* A, int l, int r,int n)
{
    TICK();
    int* B = new int[r - l + 1];
    mergesort(A,B,l,r,n);
    delete [] B;
    TOCK();
    cout<<"Time taken= "<<DURATION();
}

int radixSort(int s,int n)
{
// fill in
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
        S[i]=rand()%9999+0; //limit to 4 digit max? to be modified,maybe
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


    //Merge-sort
    startMergeSort(A,0,n-1,n);
    delete[] A;

    return 0;
}
