#include<bits/stdc++.h>
using namespace std;

int *mergemin(int a[], int n);
int rminq(int *st,int a[], int n, int ss, int se, int l,int r,int i);
void update(int *st,int a[], int n, int i, int x);

int *mergemax(int a[], int n);
int rmaxq(int *st,int a[], int n, int ss, int se, int l,int r,int i);

int *mergesum(int a[], int n);
int rsumq(int *st,int a[], int n, int ss, int se, int l, int r,int i);
void updatesum(int *st, int a[], int n, int i, int x);


int main()
{
    int a[100000];int n,i,k;
    cin>>n;
    for(i=0;i<n;i++)
        a[i]=rand()%20;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    

    //extending to 2^n
    i=1;
    while(i<n)
        i=i*2;
    k=i;
    while(i>n-1)
    {
        //a[i]=INT_MAX;
        //a[i]=INT_MIN;
        a[i]=0;
        i--;
    }
    n=k;
    //a[n]=INT_MAX;
    //a[n]=INT_MIN;
    a[n]=0;
    
    //constructing segtree
    
    int *segtree=mergesum(a,n);
    
    updatesum(segtree,a,n,1,10);
    cout<<"\n"<<a[*segtree]<<"\n";
    for(i=0;i<2*n-1;i++)
        cout<<segtree[i]<<" ";
    //cout<<s;

    //range query calls
    /*int l,r;
    cout<<"\nl,r\n";
    cin>>l>>r;
    int ans=rsumq(segtree,a,n,0,n-1,l,r,0);
    cout<<ans;*/

    //update calls
    


    return 0;
        
}


int *mergemin(int a[], int n)
{
    int i; int *st= new int[2*n-1];

    for(i=n-1;i<2*n-1;i++)
    {
        st[i]=i-n+1; //leaf nodes
    }

    i=n-2;
    while(i>-1)
    {
        if(a[st[2*i+1]]<a[st[2*i+2]])
            st[i]=st[2*i+1];
        else
            st[i]=st[2*i+2];
        i--;
    }

    return st;
}
int *mergemax(int a[], int n)
{
    int i; int *st= new int[2*n-1];

    for(i=n-1;i<2*n-1;i++)
    {
        st[i]=i-n+1; //leaf nodes
    }

    i=n-2;
    while(i>-1)
    {
        if(a[st[2*i+1]]<a[st[2*i+2]])
            st[i]=st[2*i+2];
        else
            st[i]=st[2*i+1];
        i--;
    }

    return st;
}

int rminq(int *st,int a[], int n, int ss, int se, int l,int r,int i)
{
    if (l < 0 || r > n - 1 || l > r)
    {    
        cout << "Invalid Input";
        return -1;
    }
    if (l <= ss && r >= se)  return st[i];
    if (se < l || ss > r)   return n;

    int mid=(ss+se)/2;

    int m1= rminq(st,a,n,ss,mid,l,r,2*i+1);
    int m2= rminq(st,a,n,mid+1,se,l,r,2*i+2);

    if(a[m1]<a[m2])
        return m1;
    else
        return m2;
}

int rmaxq(int *st,int a[], int n, int ss, int se, int l,int r,int i)
{
    if (l < 0 || r > n - 1 || l > r)
    {    
        cout << "Invalid Input";
        return -1;
    }
    if (l <= ss && r >= se)  return st[i];
    if (se < l || ss > r)   return n;

    int mid=(ss+se)/2;

    int m1= rminq(st,a,n,ss,mid,l,r,2*i+1);
    int m2= rminq(st,a,n,mid+1,se,l,r,2*i+2);

    if(a[m1]<a[m2])
        return m2;
    else
        return m1;
}

void update(int *st,int a[], int n, int i, int x)
{
    a[i]=x;
    i=i+n-1;
    int p = (i-1)/2;
    if(a[st[2*p+1]]<a[st[2*p+2]])
            st[p]=st[2*p+1];
        else
            st[p]=st[2*p+2];
    while(p>0)
    {
        p=(p-1)/2;
        if(a[st[2*p+1]]<a[st[2*p+2]])
            st[p]=st[2*p+1];    //st[p]=st[2*p+2]; for update max
        else
            st[p]=st[2*p+2];  
    }

}




int *mergesum(int a[], int n)
{
    int i; int *st= new int[2*n-1];

    for(i=n-1;i<2*n-1;i++)
    { //leaf nodes
        st[i]=a[i-n+1];
    }
    i=n-2;
    while(i>-1)
    {
        st[i]=st[2*i+1]+st[2*i+2];
        i--;
    }

    //for(int j=0;j<2*n-1;j++)
        //cout<<st[j]<<" ";
    return st;
}

int rsumq(int *st,int a[], int n, int ss, int se, int l, int r,int i)
{
    if (l < 0 || r > n - 1 || l > r)
    {    
        cout << "Invalid Input";
        return -1;
    }
    if (l <= ss && r >= se)  return st[i];
    if (se < l || ss > r)   return 0;

    int mid=(ss+se)/2;

    return (rsumq(st,a,n,ss,mid,l,r,2*i+1)+rsumq(st,a,n,mid+1,se,l,r,2*i+2));

}

void updatesum(int *st, int a[], int n, int i, int x)
{
    a[i]=x;
    i=i+n-1;
    st[i]=x;
    int p=(i-1)/2;
    st[p]=st[2*p+1]+st[2*p+2];
    while(p>0)
    {
        p=(p-1)/2;
        st[p]=st[2*p+1]+st[2*p+2];
    }
}