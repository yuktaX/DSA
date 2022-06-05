#include<stdio.h>
void mergesort(int a[], int p, int r);
void merge(int a[], int p, int q, int r);
void display(int a[], int n);
void mergesort(int a[], int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);

    }
}
void merge(int a[], int p, int q, int r)
{
    int n1=q-p+1; int n2=r-q;
    int b[n1], c[n2];
    int k;
    for(int i=0;i<n1;i++)
        b[i]=a[p+i]; //transferring elements to 2 arrays
    for(int j=0;j<n2;j++)
        c[j]=a[q+1+j];

    int i,j;
    i=0;j=0; //pointers for b and c arrays
    k=p; //pointer for main array into which we overwrite

    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
        }
        else
        {
            a[k]=c[j];j++;
        }
        k++;
    }
    while(i<n1) //for remaining elements
    {
        a[k]=b[i]; 
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=c[j];
        j++;k++;    
    }   
}
void display(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main()
{
    int n,i,j,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    display(a,n);
    printf("\n");
    mergesort(a,0,n-1);
    display(a,n);
}
