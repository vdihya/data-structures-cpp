#include<bits/stdc++.h>
using namespace std;

int * insertion(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int val = *(a+i); // at a[i]
        int j = i - 1;

        while(j>=0 && *(a+j)>val)
        {
            *(a+j+1) = *(a+j);
            j-=1;
        }
        *(a+j+1) = val;
    }

    return a;
}

void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int partition_(int a[],int beg, int en)
{
    int i = beg+1; // portion of elements > and < than pivot
    int pivot = a[beg];
    for(int j = beg+1;j<=en;j++)
    {
        if(a[j]<pivot)
        {
           swap(a[i],a[j]); // moving all elements less than pivot to before the pivot
           i=i+1;
        }

    }
    swap(a[beg],a[i-1]);
    return i-1;
}

void quicksort(int a[],int beg, int en)
{
    if(beg < en)
    {
        int pivot = partition_(a,beg,en);
        quicksort(a,beg,pivot-1);
        quicksort(a,pivot+1,en);
    }
    return;

}

void merges(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r)
{
  if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merges(arr, l, m, r);
    }
}

void selection(int arr[], int n)
{

    for(int i=0;i<n-1;i++)
    {
        int min_ = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_])
                min_ = j;
        }
        swap(arr[min_],arr[i]);

    }
}

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[largest] < arr[left])
        largest = left;
    if(right<n && arr[largest] < arr[right])
        largest = right;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);

    }

}

void heapsort(int arr[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        heapify(arr, n, i);
    for(int i=n-1;i>0;i--)
    {
        printarray(arr,n);
        swap(arr[0],arr[i]);
        printf("after swap:\n");
        printarray(arr,n);

        heapify(arr, i, 0);
        printf("after heapify:\n");
        printarray(arr,n);

    }

}

void countsort(int arr[],int n)
{
    int maxx = *max_element(arr,arr+n);
    int minn = *min_element(arr,arr+n);
    int range = maxx - minn + 1;

    vector<int> countarr(range),output(n);

    for(int i=0;i<n;i++)
        countarr[arr[i] - minn]++;

    for(int i=1;i<countarr.size();i++)
        countarr[i]+=countarr[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[countarr[arr[i] - minn]-1] = arr[i];
        countarr[arr[i]-minn]--;
    }
    for(int i=0;i<n;i++)
        arr[i] = output[i];
}

void radixcount(int arr[],int n, int exp)
{
    vector<int> countarr(11,0);
    vector<int> output(n);

    for(int i=0;i<n;i++)
    {
        countarr[(arr[i]/exp)%10]++;
        printf("countarr[%d] = %d\n",i,countarr[i]);

    }


    for(int i=1;i<10;i++)
     {printf("%d ",countarr[i-1]);
        countarr[i] += countarr[i-1];

     }

    for(int i=n-1;i>=0;i--)
    {
        output[ countarr[ (arr[i]/exp)%10 ] -1 ] = arr[i];
        countarr[ (arr[i]/exp)%10 ]--;
    }

    for(int i=0;i<n;i++)
        arr[i] = output[i];
}
void radixsort(int arr[],int n)
    {
        int m = *max_element(arr, arr+n);
        for (int exp = 1; m/exp > 0; exp *= 10)
        {
                 printf("e=%d",exp);
            radixcount(arr, n, exp);

        }
    }

void bucketsort(float arr[],int n)
{
    vector<float> buckets[n];

    for(int i=0;i<n;i++)
    {
        int b = n*arr[i];
        buckets[b].push_back(arr[i]);

    }
    for(int i=0;i<n;i++)
        sort(buckets[i].begin(),buckets[i].end());

    int k = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<buckets[i].size();j++)
            arr[k++] = buckets[i][j];


}
void bucketprint(float a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%f ",a[i]);
    printf("\n");
}
int main()
{
    int a[] = {4,10,5};
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(a)/sizeof(a[0]);
    int arrn = sizeof(arr)/sizeof(arr[0]);
    //insertion(a,n);
    //quicksort(a,0,n-1);
    //mergesort(a,0,n-1);
    //selection(a,n);
    //heapsort(a,n);
    //countsort(a,n);
    //radixsort(a,n);
    //bucketsort(arr,arrn);
    //bucketprint(arr,arrn);
    return 0;
}
