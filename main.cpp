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

void quickSort(int* A, int p, int r)
{
    int pivot;
    if (p < r)
    {
        pivot = partition(A, p, r);
        quickSort(A, p, pivot -1);
        quickSort(A, pivot+1, r);
    }
}

int partition2(int* A,int p, int r)
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
        /*if(n<=100)//we only show results of short array
        {
        cout<<"p="<<l<<", r="<<r<<", array=";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        }*/
    }

}

int startMergeSort(int* A, int l, int r,int n)
{
    int* B = new int[r - l + 1];
    mergesort(A,B,l,r,n);
    delete [] B;
}


void NewMerge(int *A,int *L,int leftCount,int *R,int rightCount) { //Alternative code
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void NewMergeSort(int *A,int n) {                                  //Alternative code
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing.

	mid = n/2;  // find the mid index.

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	NewMergeSort(L,mid);  // sorting the left subarray
	NewMergeSort(R,n-mid);  // sorting the right subarray
	NewMerge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}




int radixSort(int* A,int n,int largest)
{
    //int divide=1;
    int mod=10;
    int temp;

    int exp=1;
    for (int i=0; i<= largest > 0;i++ )
    {
        int* output=new int[n];
        int count[10] = {0};
        int temp;
        for (int i = 0; i < n; i++)
        {
            temp=(A[i]/exp)%10;
            count[temp]=count[temp]+1;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] =count[i]+count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            temp=(A[i]/exp)%10;
            output[count[temp]-1] = A[i];
            count[temp]--;
        }

        for (int i = 0; i < n; i++)
        {
           A[i] = output[i];
        }
        exp =exp* 10;
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
    cout<<"######################################################"<<endl;
    cout<<"# Comparison of Quick-sort,Radix-sort and Merge-sort #"<<endl;
    cout<<"######################################################"<<endl<<endl;

    int n;
    cout<<"Please input number of array: ";
    cin>>n;
    cout<<endl;

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
    cout<<endl<<endl;

    //copy array for reuse
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }


    //Quick-sort
    system("pause");
    cout<<"Quick Sort: "<<endl;
    TICK();
    quickSort(A, 0 ,n-1);
    TOCK();
    for(int i=0;i<n;i++)
        {
            //cout<<A[i]<<" ";
        }
    cout<<"Time taken= "<<DURATION()<<endl<<endl;

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
    radixSort(A,n,digits);
    TOCK();
    cout<<"Time taken= "<<DURATION()<<endl<<endl;
    system("pause");


    //Merge-sort
    for(int i=0;i<n;i++)
    {
        A[i]=S[i];
    }
    cout<<"Merge Sort: ";
    TICK();

    //startMergeSort(A,0,n-1,n);
    NewMergeSort(A,n);

    startMergeSort(A,0,n-1,n);
    TOCK();

    for(int i=0;i<n;i++)
        {
            //cout<<A[i]<<" ";
        }
        cout<<endl;

    cout<<"Time taken= "<<DURATION()<<endl;
    //delete[] A;


    return 0;
}
