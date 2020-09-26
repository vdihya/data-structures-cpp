#include<bits/stdc++.h>
using namespace std;

void printarray(string arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;

}
void bubblesort(string arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > (arr[j+1]))
                swap(arr[j],arr[j+1]);

        }
    }

}
void merges(string arr[],int l,int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i,j,k;
    string L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i]= arr[l+i];

    for(j=0;j<n2;j++)
        R[j]= arr[m+j+1];

    i=0; j=0; k=l;

    while(i<n1 && j<n2)
    {
        if((L[i]<=R[j]))
        {
             arr[k] = L[i];
             i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}
void mergesort(string arr[], int l, int r)
{
    if(l < r)
    {
        int m =  l + (r - l) /2;

        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merges(arr, l, m, r);
    }
}

int main()
{
    string names[]={"xyz","xaz","abc","arstdm","fgdh"};
    int n = sizeof(names)/sizeof(names[0]);
    printarray(names,n);
    bubblesort(names,n);
    cout<<"sorted:"<<endl;
    printarray(names,n);
    cout<<"mergesorted:"<<endl;
    mergesort(names,0,n-1);
    printarray(names,n);
    return 0;
}
