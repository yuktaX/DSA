#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int tmp;
    tmp=*x;*x=*y;*y=tmp;
}
int partition(int a[],int l,int r)
{
    int p,i,j;
    p=rand()%(r-l+1) + l;
    i=l-1;
    swap(&a[p],&a[r]);
    for(j=l;j<r;j++)
    {
        if(a[j]<a[p])
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;

}
int findr(int a[], int l,int  r,int rank)
{
    int k,p;
    if(l<r)
    {
    p=rand()%(r-l+1)+l;
    swap(&a[p],&a[l]);
    k=partition(a,l,r);
    if(rank==r-k+1)
        return k;
    else if(rank<r-k+1)
        return findr(a,k+1,r,rank);
    else
        return findr(a,l,k-1,rank-r+k-1);
    }
    return r;
}
int main()
{
    int a[10000]; int i,rank,n,ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>rank;
    ans=findr(a,0,n,rank);
    cout<<ans;
}