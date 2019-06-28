#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a;
    ll b;
};

void buildTree(node * arr, ll * tree, ll l, ll r, ll i)
{
    if(l==r)
    {
        tree[i] = l;
        return;
    }
    
    ll mid = (l+r)/2;
    buildTree(arr,tree,l,mid,2*i);
    buildTree(arr,tree,mid+1,r,2*i+1);
    
    ll lans = tree[2*i];
    ll rans = tree[2*i+1];
    
    if(arr[lans].a>arr[rans].a)
    {
        tree[i] = lans;
    }
    
    else if(arr[lans].a<arr[rans].a)
    {
        tree[i] = rans;
    }
    
    else
    {
        if(arr[lans].b<arr[rans].b)
        {
            tree[i] = lans;
        }
        
        else if(arr[lans].b>arr[rans].b)
        {
            tree[i] = rans;
        }
        
        else
        {
            tree[i] = lans;
        }
    }
    
    return;
}

ll queryTree(node * arr,ll * tree, ll s, ll e, ll i, ll l, ll r)
{
    if(s>r || e<l)return -1;
    if(s>=l && e<=r)return tree[i];
    ll mid = (s+e)/2;
    
    ll lans = queryTree(arr,tree,s,mid,2*i,l,r);
    ll rans = queryTree(arr,tree,mid+1,e,2*i+1,l,r);
    ll ans = 0;
    
    if(lans==-1)
    {
        ans = rans;
        return ans;
    }
    
    else if(rans==-1)
    {
        ans = lans;
        return ans;
    }
    
    if(arr[lans].a>arr[rans].a)
    {
        ans = lans;
    }
    
    else if(arr[lans].a<arr[rans].a)
    {
        ans = rans;
    }
    
    else
    {
        if(arr[lans].b<arr[rans].b)
        {
            ans = lans;
        }
        
        else if(arr[lans].b>arr[rans].b)
        {
            ans = rans;
        }
        
        else
        {
            ans = lans;
        }
    }
    
    return ans;
    
    
}
int main() {

	// Write your code here
    
    ll n;
    cin>>n;
    
    ll * arr1 = new ll[n];
    ll * arr2 = new ll[n];
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=0;i<n;i++)cin>>arr2[i];
    
    node * arr = new node[n];
    for(int i=0;i<n;i++)
    {
        arr[i].a = arr1[i];
        arr[i].b = arr2[i];
    }
    ll * tree = new ll[4*n];
    buildTree(arr,tree,0,n-1,1);
    // for(int i=1;i<2*n;i++)cout<<tree[i]<<" ";
    // cout<<endl;
    int q;
    cin>>q;
    
    for(int i=0;i<q;i++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<queryTree(arr,tree,0,n-1,1,l-1,r-1)+1<<endl;
    }
    
}