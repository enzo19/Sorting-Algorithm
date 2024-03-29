#include <iostream>
#include "timer.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

int partition(int* A,int p, int r, bool steps, int n)
{
    int i = p-1;    //set i to the part beside smallest index, p
    int j;
    for(j = p; j<r ;j++)   //loop each index until r
    {
        if (A[j] <= A[r]){ //Compare index j with pivot, last index is chosen as pivot
            i++;
            swap(A[i], A[j]); //If j is larger swap with index i
        }
    }

    swap(A[i + 1], A[r]);   //swap the pivot to i+1, which is right side of the partition wall
    if(steps){
        cout<<"p="<<p<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)  //display each steps of swap in partitioning, left smaller than pivot, right larger than pivot
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
return i + 1; //return index to quick sort function to perform ascending order sort
}


void quickSort(int* A, int p, int r, bool steps, int n)
{
    //Recursion
    int pivot;
    if (p < r)  //when p is smaller than r
    {
        pivot = partition(A, p, r, steps, n); //state pivot in partition function
        quickSort(A, p, pivot -1,steps, n); //recursive function call for index left side of pivot
        quickSort(A, pivot+1, r,steps, n);  //recursive function call for index right side of pivot
        //if(steps){
        //cout<<"array=";
        if(steps){
            cout<<"p="<<p<<", r="<<r<<", array="; //display current p and r index
        for(int i=0;i<n;i++)    //display each steps of swap in quick sort in ascending order, left smaller than pivot, right larger than pivot
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }


    }
}



//############################################################################

void mergesort(int* A, int* B, int p, int r,int n,bool steps)
{
    if(p<r){
        int m=(p+r)/2; //divide the array,m is the middle
        mergesort(A,B,p,m,n,steps); //call recursively from first to middle
        mergesort(A,B,m+1,r,n,steps);//call recursively from middle to last
        int i, j;
        for (i = m + 1; i > p; i--)
            {
                B[i - 1] = A[i - 1]; //copy the value from first sorted partition
                //e.g B[2]=A[2], B[1]=A[1], B[0]=A[0]
                //e.g i=0 ,use this value for next step
            }

        for (j = m; j < r; j++)
            {
                B[r + m - j] = A[j + 1]; //copy the value of second sorted partition
                //descending it so ,because we compare smallest from each partition ,e.g B[4]=3 ,B[3]=4
                //e.g j=4 ,use this value for next step
            }
        for (int k = p; k <= r; k++)
            {
                if (B[j] < B[i])    //compare B[j]to B[i](first of different partition), if B[j]less than B[i]
                    {
                        A[k] = B[j--];  //A[k]=B[j],then minus value of j
                    }
                else
                    {
                        A[k] = B[i++]; //A[k]=B[j],then increase value of i
                    }
            }

        if(steps){
            cout<<"p="<<p<<", r="<<r<<", array="; //display current p and r index
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" "; //display each steps of merges sort
        }
        cout<<endl;
        }

    }

}

int startMergeSort(int* A, int p, int r,int n,bool steps)
{
    int* B = new int[n];
    mergesort(A,B,p,r,n,steps);
    delete [] B;
}
//############################################################################

int radixSort(int* A,int n,int largest,bool steps)
{
    int divide=1;
    int mod=10;
    int temp;
    // largest is the number of digits
    for (int i=0; i< largest > 0;i++ )
    {
        int* newArray=new int[n]; //an temp array
        int digits[10] = {0}; //array to store size of bucket of each digits
        int temp;
        for (int i = 0; i < n; i++)
        {
            temp=(A[i]/divide)%mod; //divide integer and modulus to get the digits
            digits[temp]=digits[temp]+1; //count the occurrence of digits in the array
        }

        for (int i = 1; i < 10; i++)
        {
            digits[i] =digits[i]+digits[i - 1]; //get the actual position by cumulatively
        }

        for (int i = n - 1; i >= 0; i--)
        {
            temp=(A[i]/divide)%mod;
            newArray[digits[temp]-1] = A[i];//put the integer in temp array by descending
            digits[temp]--;  //minus the occurrence so that next position right
        }

        for (int i = 0; i < n; i++)
        {
           A[i] = newArray[i]; //copy back to the original array
        }

        divide =divide* mod; //increase the divide number for next digits'loop

        if(steps){ //show steps if enabled
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
    double quickTime,radixTime,mergeTime;
    cout<<"Before: ";
    //Initialize random array
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        S[i]=rand();
        if(n<1000){
        cout<<S[i]<<" ";}
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
    quickSort(A, 0 ,n-1,showSteps, n);
    TOCK();
    quickTime=DURATION();
    cout<<"Result= ";
    for(int i=0;i<n;i++)
    {
        if(n<1000){
            cout<<A[i]<<" ";}
    }
    cout<<endl;
    if(quickTime<0.001)
    {
        cout<<"Time taken= "<<quickTime*1000<<" milliseconds"<<endl<<endl;
    }
    else
    {
        cout<<"Time taken= "<<quickTime<<" seconds"<<endl<<endl;

    }

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
    radixTime=DURATION();
    cout<<"Result= ";
    for(int i=0;i<n;i++)
    {
         if(n<1000){
            cout<<A[i]<<" ";}
    }
    cout<<endl;

    if(radixTime<0.001)
    {
        cout<<"Time taken= "<<radixTime*1000<<" milliseconds"<<endl<<endl;
    }
    else
    {
        cout<<"Time taken= "<<radixTime<<" seconds"<<endl<<endl;

    }
    system("pause");


    //############################################################################
    //Merge-sort
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }
    cout<<"Merge Sort: "<<endl;
    TICK();

    //startMergeSort(A,0,n-1,n);
    //NewMergeSort(A,n);

    startMergeSort(A,0,n-1,n,showSteps);
    TOCK();
    mergeTime=DURATION();
    cout<<"Result= ";
    for(int i=0;i<n;i++)
    {
        if(n<1000){
            cout<<A[i]<<" ";}
    }
    cout<<endl;

    if(mergeTime<0.001)
    {
        cout<<"Time taken= "<<mergeTime*1000<<" milliseconds"<<endl<<endl;
    }
    else
    {
        cout<<"Time taken= "<<mergeTime<<" seconds"<<endl<<endl;

    }
    //############################################################################
    if((quickTime<radixTime)&&(quickTime<mergeTime))
    {
        cout<<"QuickSort is the fastest in this experiment"<<endl;
    }
    else if((radixTime<quickTime)&&(radixTime<mergeTime))
    {
        cout<<"RadixSort is the fastest in this experiment"<<endl;
    }
    else if((mergeTime<quickTime)&&(mergeTime<radixTime))
    {
        cout<<"MergeSort is the fastest in this experiment"<<endl;
    }
    return 0;
}
