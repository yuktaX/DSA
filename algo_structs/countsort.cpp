#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n)
{
    int b[10000];int i; int c[10000]={0}; int m=arr[0];
    for(i=0;i<n;i++)
        m=max(arr[i],m);
    for(i=0;i<n;i++)
    {
        c[arr[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        c[i]+=c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;

    }
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}

int main()
{
    int n; int arr[10000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    count(arr,n);
    return 0;
}