#include<bits/stdc++.h>

using namespace std;

void update(int * arr,int * tree, int si,int ei, int ci, int i,int val)
{
    if(si==i && ei==i)
    {
        arr[i] = val;
        tree[ci] = val;
        return;
    }
    
    int mid = (si+ei)/2;
    if(i<=mid)
    {
    	update(arr,tree,si,mid,2*ci,i,val);
    }
    
    else
    {
    	update(arr,tree,mid+1,ei,2*ci+1,i,val);
    }
    tree[ci] = min(tree[2*ci],tree[2*ci+1]);
    return;
}

int query(int * tree, int si, int ei, int ci, int qi, int qe)
{
    //cout<<si<<" "<<ei<<" "<<qi<<" "<<qe<<endl;
    if(si==qi && ei==qe)
    {
        return tree[ci];
    }
    
    int mid = (si+ei)/2;
    
    if(mid<qi)
    {
        return query(tree,mid+1,ei,2*ci+1,qi,qe);
    }
    
    else if(mid>=qe)
    {
        return query(tree,si,mid,2*ci,qi,qe);
    }
    
    else
    {
        return min(query(tree,si,mid,2*ci,qi,mid),query(tree,mid+1,ei,2*ci+1,mid+1,qe));
    }
    
}

void build(int * arr, int * tree, int si, int ei, int ci)
{
    if(si==ei)
    {
        tree[ci] = arr[si];
        return;
    }
    
    int mid = (si+ei)/2;
    build(arr,tree,si,mid,2*ci);
    build(arr,tree,mid+1,ei,2*ci+1);
    
    tree[ci] = min(tree[2*ci],tree[2*ci+1]);
}

int main()
{
    int n,p;
    cin>>n>>p;
    
    int * arr = new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int * tree = new int[2*n];
    memset(tree,0,sizeof(int)*2*n);
    
    build(arr,tree,0,n-1,1);
    for(int i=0;i<2*n;i++)cout<<tree[i]<<" ";
    cout<<endl;	
    for(int i=0;i<p;i++)
    {
        char choice;
        cin>>choice;
        
        if(choice=='q')
        {
            int qi,qe;
            cin>>qi>>qe;
            cout<<query(tree,0,n-1,1,qi,qe)<<endl;
        }
        
        else
        {
            int i,val;
            cin>>i>>val;
            update(arr,tree,0,n-1,1,i,val);
        }
    }
    
    for(int i=0;i<2*n;i++)cout<<tree[i]<<" ";
    cout<<endl;
}
