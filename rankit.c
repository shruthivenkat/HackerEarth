#include<stdio.h>
int binary(long long int a[], int n, long long int x)
{
    int low=0, high=n-1, mid;

    while(low <= high)
    {
        mid = low+(high-low)/2;
        if(a[mid] == x)
            return mid+1;
        else if(a[mid] > x)
            high = mid-1;
        else if(a[mid] < x)
            low = mid+1;
    }
    return -1;
}
void insertion(long long int a[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        int j=i-1, key = a[i];
        while(j>=0 && key < a[j])
        a[j+1] = a[j--];
        a[j+1] = key;
    }
}

int main()
{
    int n, q, i;
    scanf("%d",&n);
    long long int a[n], x;
    for(i=0; i<n; i++)
         scanf("%lld",&a[i]);
    insertion(a, n);
    scanf("%d",&q);
    while(q--)  
    {   
         scanf("%lld",&x);
        printf("%d\n",binary(a, n, x));
    }
}
