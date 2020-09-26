
#include<bits/stdc++.h>
using namespace std;
void jump(int [], int [], int [], int);
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int jumps[n+1];
    for(int i=0;i<n;i++) jumps[i] = 999;

    jumps[0] = 0;
    int from[n+1];

    jump(arr,jumps,from,n);


}

void jump(int arr[],int jumps[],int from[], int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i)
            {
                int minv = min(jumps[j] +1,jumps[j]-1);
                jumps[i] = min(jumps[i],minv);
                from[i] = j;
            }
        }
    }
    printf("%d",jumps[n-1]);
}
