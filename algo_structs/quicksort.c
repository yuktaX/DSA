
#include<stdio.h>
#include<stdlib.h>
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
void rqs(int a[], int l,int r)
{
    int j;
    if (l<r)
    {
        j=partition(a,l,r);
        rqs(a,l,j);
        rqs(a,j+1,r);
    }
}
int main()
{
    int n,i,j,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    rqs(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}