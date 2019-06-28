#include<bits/stdc++.h>
using namespace std;

int arr[100004];
int tree[4*100004];

void buildTree(int l, int r, int i)
{
    if(l==r)
    {
        tree[i] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    buildTree(l,mid,2*i);
    buildTree(mid+1,r,2*i+1);
    
    tree[i] = min(tree[2*i],tree[2*i+1]);
}

void updateTree(int l, int r, int i, int index, int val)
{
    if(l==r)
    {
        arr[index] = val;
        tree[i] = val;
        return;
    }
    
    int mid = (l+r)/2;
    if(index>mid)
    {
        updateTree(mid+1,r,2*i+1,index,val);
    }
    
    else
    {
        updateTree(l,mid,2*i,index,val);
    }
    
    tree[i] = min(tree[2*i],tree[2*i+1]);
}

int queryTree(int s, int e, int i, int l, int r)
{
    if(s>r || e<l)return 1000000007;
    if(s>=l && e<=r)
    {
        return tree[i];
    }
    
    int mid = (s+e)/2;
    int lans = queryTree(s,mid,2*i,l,r);
    int rans = queryTree(mid+1,e,2*i+1,l,r);
    return min(lans,rans);
}

int main() {

	// Write your code here
    
    int n, q;
    cin>>n>>q;
    
    
    for(int i=0;i<n;i++)cin>>arr[i];
    
    buildTree(0,n-1,1);
    for(int i=0;i<q;i++)
    {
        char c;
        int l,r;
        cin>>c>>l>>r;
        
        if(c=='q')
        {
            cout<<queryTree(0,n-1,1,l-1,r-1)<<endl;
        }
        
        else
        {
            updateTree(0,n-1,1,l-1,r);
        }
    }
}