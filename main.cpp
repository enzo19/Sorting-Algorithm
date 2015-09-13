#include <iostream>
#include "timer.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

int partition(int* A,int p, int r)
{
    int i = p-1;
    int j;
    for(j = p; j<r ;j++)
    {
        if (A[j] <= A[r]){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
return i + 1;
}

void quickSort(int* A, int p, int r, bool steps)
{
    int pivot;
    if (p < r)
    {
        pivot = partition(A, p, r);
        quickSort(A, p, pivot -1,steps);
        quickSort(A, pivot+1, r,steps);

        if(steps){
        cout<<"array=";
        for(int i=0;i<r+1;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }
    }
}

/*int partition2(int* A,int p, int r)
{
    int i = p-1;
    int j;
    for(j = p; j>r ;j++)
    {
        if (A[j] <= A[r]){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
return i + 1;
}

void quickSort2(int* A, int p, int r)
{
    int pivot;
    if (p < r)
    {
        pivot = partition2(A, p, r);
        quickSort(A, p, pivot -1);
        quickSort(A, pivot+1, r);
    }
}
*/
//############################################################################


void merge(int* A, int* B, int l, int m, int r)
{
    int i, j;
    for (i = m + 1; i > l; i--)

        B[i - 1] = A[i - 1];

    for (j = m; j < r; j++)

        B[r + m - j] = A[j + 1];

    for (int k = l; k <= r; k++)
        if (B[j] < B[i])

            A[k] = B[j--];

        else

            A[k] = B[i++];
}

void mergesort(int* A, int* B, int l, int r,int n,bool steps)
{
    if(l<r){
        int m=(l+r)/2; //divide
        mergesort(A,B,l,m,n,steps);
        mergesort(A,B,m+1,r,n,steps);
        merge(A,B,l,m,r);

        if(steps){
        cout<<"p="<<l<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }
    }

}

int startMergeSort(int* A, int l, int r,int n,bool steps)
{
    int* B = new int[r - l + 1];
    mergesort(A,B,l,r,n,steps);
    delete [] B;
}
//############################################################################

int radixSort(int* A,int n,int largest,bool steps)
{
    int divide=1;
    int mod=10;
    int temp;

    for (int i=0; i< largest > 0;i++ )
    {
        int* output=new int[n];
        int count[10] = {0};
        int temp;
        for (int i = 0; i < n; i++)
        {
            temp=(A[i]/divide)%mod;
            count[temp]=count[temp]+1;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] =count[i]+count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            temp=(A[i]/divide)%mod;
            output[count[temp]-1] = A[i];
            count[temp]--;
        }

        for (int i = 0; i < n; i++)
        {
           A[i] = output[i];
           /*if(steps)
            {
                cout<<A[i]<<" ";
            }*/
        }
        divide =divide* mod;
        if(steps){
        cout<<"array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }
    }


    //code 02
    /*int *W=new int[n];
    int *Z=new int[n];

    for (int i = 0; i <= largest; i++)
    {
        for (int i = 0; i < n; i++)
        {
            W[i]=(A[i]/divide)%10;
        }
        int c=0;

        for(int j=0;j<10;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(W[i]==j)
                {
                    Z[c]=A[i];
                    c=c+1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            //A[i]=Z[i];
        }
        divide=divide*mod;
    }*/


    //code 03
    /*queue<int> bucket[10];
    for(int i=0;i<=largest;i++)
    {
        //cout<<i<<endl;
        for(int j=0;j<n;j++)
        {
            temp=(A[j]/divide)%mod;
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
    }*/
}

int main()
{
    cout<<"#######################################################################"<<endl;
    cout<<"#          Comparison of Quick-sort,Radix-sort and Merge-sort         #"<<endl;
    cout<<"#######################################################################"<<endl<<endl;

    bool showSteps=false;
    int n;
    char selectSteps;
    cout<<"Please input number of array: ";
    cin>>n;
    cout<<"Do you want to show steps of algorithm?(y/n) ";
    cin>>selectSteps;
    if(selectSteps=='y')
    {
        showSteps=true;
    }
    else
    {
        showSteps=false;
    }
    cout<<endl;
    int *S=new int[n];
    int *A=new int[n];

    cout<<"Before: ";
    //Initialize random array
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        S[i]=rand();
        if(n<=100)
        {
            cout<<S[i]<<" ";
        }
    }
    cout<<endl<<endl;
    //############################################################################
    //Quick-sort
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }
    system("pause");
    cout<<"Quick Sort: "<<endl;
    TICK();
    quickSort(A, 0 ,n-1,showSteps);
    TOCK();
    for(int i=0;i<n;i++)
        {
            //cout<<A[i]<<" ";
        }
    cout<<"Time taken= "<<DURATION()<<endl<<endl;


    //############################################################################
    //Radix-sort
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
    int digits;
    int divide=1;
    for(digits=0;largest/divide>0;digits++)
    {
         divide=divide*10;
    }
    system("pause");
    cout<<"Radix Sort: "<<endl;
    TICK();
    radixSort(A,n,digits,showSteps);
    TOCK();
    cout<<"Time taken= "<<DURATION()<<endl<<endl;
    system("pause");


    //############################################################################
    //Merge-sort
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }
    cout<<"Merge Sort: ";
    TICK();

    //startMergeSort(A,0,n-1,n);
    //NewMergeSort(A,n);

    startMergeSort(A,0,n-1,n,showSteps);
    TOCK();

    for(int i=0;i<n;i++)
        {
            //cout<<A[i]<<" ";
        }
        cout<<endl;

    cout<<"Time taken= "<<DURATION()<<endl;
    //delete[] A;

    //############################################################################

    return 0;
}
