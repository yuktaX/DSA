#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[], int l, int r, int x)
{
  int m = (l+r)/2;
  while(l<=r)
  {
    if(arr[m]==x)
    return m;
    else if(arr[m]>x)
    return(bsearch(arr,l,m-1,x));
    else if(arr[m]<x)
    return(bsearch(arr,m-1,r,x));
  }
  return 0;
}
int main()
{
    int n,l,r,ans;
    scanf("%d",&n);
    int a[]={1,2,3,4,5,6,9}; //sorted array
    ans=bsearch(a,0,7,n);
    if(ans)
        cout<<"Yes "<<ans;
    else
        cout<<"No";
    return 0;
}