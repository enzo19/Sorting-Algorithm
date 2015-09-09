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
        int m=(l+r)/2;
        mergesort(A,B,l,m,n);
        mergesort(A,B,m+1,r,n);
        merge(A,B,l,m,r);

        cout<<"p="<<l<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
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
    int S[n];
    int mergeArray[n];
    int quickArray[n];
    int radixArray[n];

    cout<<"Before: ";
    //Initialize random array
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        S[i]=rand()%9999+0; //limit to 4 digit max? to be modified,maybe
        cout<<S[i]<<" ";
    }
    cout<<endl;
    //copy array for reuse
    for(int i=0;i<n;i++)
    {
        mergeArray[i]=S[i];
        quickArray[i]=S[i];
        radixArray[i]=S[i];
    }

    //Quick-sort


    //Radix-sort


    //Merge-sort
    startMergeSort(mergeArray,0,n-1,n);

    return 0;
}
