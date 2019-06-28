#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll mxsum;
    ll sum;
    ll ss;
    ll ps;
};

void buildTree(ll * arr, node * tree, ll l, ll r, ll i)
{
    if(l==r)
    {
        node ans;
        ans.mxsum = arr[l];
        ans.sum = arr[l];
        ans.ss = arr[l];
        ans.ps = arr[l];
        tree[i] = ans;
        return;
    }
    
    ll mid = (l+r)/2;
    buildTree(arr,tree,l,mid,2*i);
    buildTree(arr,tree,mid+1,r,2*i+1);
    node lans = tree[2*i];
    node rans = tree[2*i+1];
    tree[i].mxsum = max(max(lans.mxsum,rans.mxsum),max(lans.sum+rans.ps,max(lans.ss+rans.sum,lans.ss+rans.ps)));
    tree[i].sum = lans.sum+rans.sum;
    tree[i].ss = max(lans.ss+rans.sum,rans.ss);
    tree[i].ps = max(lans.sum+rans.ps,lans.ps);
    return;
}

node queryTree(ll * arr, node* tree, ll s, ll e, ll i, ll l, ll r)
{
    if(s>r || e<l)
    {
        node ans;
        ans.mxsum = INT_MIN;
        ans.sum = INT_MIN;
        ans.ps = INT_MIN;
        ans.ss = INT_MIN;
        return ans;
    }
    
    if(s>=l && e<=r)
    {
        return tree[i];
    }
    
    ll mid = (s+e)/2;
    
    node lans = queryTree(arr,tree,s,mid,2*i,l,r);
    node rans = queryTree(arr,tree,mid+1,e,2*i+1,l,r);
    
    node ans;
    ans.mxsum = max(max(lans.mxsum,rans.mxsum),max(lans.sum+rans.ps,max(lans.ss+rans.sum,lans.ss+rans.ps)));
    ans.sum = lans.sum+rans.sum;
    ans.ss = max(lans.ss+rans.sum,rans.ss);
    ans.ps = max(lans.sum+rans.ps,lans.ps);
    return ans;
}

int main() {

    // Write your code here
    
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    node * tree = new node[4*n];
    buildTree(arr,tree,0,n-1,1);
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        
        cout<<queryTree(arr,tree,0,n-1,1,l-1,r-1).mxsum<<endl;
    }
}