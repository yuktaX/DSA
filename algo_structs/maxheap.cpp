#include<bits/stdc++.h>
using namespace std;

void
MaxTopdownheapify (int H[], int i, int n)
{
  int c, t,temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] > H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] < H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] < H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      i = c;
    }

}


void
MaxBuildHeap (int H[],  int n)
{

  int i = n / 2;
  while (i > -1)
    {
      MaxTopdownheapify (H, i--, n);
    }

}
void
DeleteMax (int H[], int *n)
{
  int t;
  
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  MaxTopdownheapify (H, 0, *n);
}
void
HeapSort (int H[],  int n)
{

  int m=n,i;
  MaxBuildHeap(H,n);
  for(i=0;i<n;++i) DeleteMax(H,&m);

  for(i=0;i<n-1;++i) if(H[i]>H[i+1]) cout<<"Problem";

}
int main()
{
    int h[]={2,5,6,9,1,7};
    int n=6;
    HeapSort(h,n);
    for(int i=0;i<n;i++)
        cout<<h[i]<<" ";
    return 0;
}