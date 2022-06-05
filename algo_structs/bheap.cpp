#include<bits/stdc++.h>
using namespace std;

void bottomupheapify(int h[], int i) //i is current node
{
    int p=(i-1)/2; int tmp;
    while(p>-1)
    {
        if(h[i]<h[p])
        {
            tmp=h[i];h[i]=h[p];h[p]=tmp;
            i=p;
            p=(i-1)/2;
        }
        else
            p=-1;
    }
}
void topdownheapify(int h[], int i, int *n)
{
    int c;
    while(2*i+2<*n)
    {
        if(h[2*i +1]<h[2*i +2]) //comparing both children and keeping track of minimum
            c=2*i+1;
        else
            c=2*i+2;
        if(h[i]>h[c]) //if parent is greater than min of 2 children swap
        {
            int tmp;
            tmp=h[i]; h[i]=h[c];h[c]=tmp;
            i=c;
        }
        else
            i=*n;
        c=2*i+1;
        if(c<*n && h[i]>h[c])
        {
            int tmp;
            tmp=h[i];h[i]=h[c];h[c]=tmp;
        }
    }
}
void add(int h[], int x , int *n)  //n is pointer to last node
{
    h[*n]=x;
    *n=*n+1;
    bottomupheapify(h, *n-1);
}

void delmin(int h[], int *n)
{
    int tmp;
    *n=*n-1;
    tmp=h[0];h[0]=h[*n];h[*n]=tmp; //swap last element with root aka smallest ele
    topdownheapify(h,0,*n);
}
