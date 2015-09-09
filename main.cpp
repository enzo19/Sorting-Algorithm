#include <iostream>
using namespace std;
#include "timer.h"
#include <string>

int quickSort(int s,int n)
{
// fill in
}

int mergeSort(int s,int n)
{
// fill in
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
    cout<<"Please input the size of array";
    int n;
    cin>>n;
    int S[n];

    cout<<"Original: \n";

    for(int i=0;i<n;i++)
    {
        TICK();
        //_sleep(2000);
        S[i]=rand();
        cout<<S[i]<<" ";
        TOCK();

    }
    cout<<"Time taken= "<<DURATION();
}
