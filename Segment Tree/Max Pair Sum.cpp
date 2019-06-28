#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll mx;
    ll smx;
};





void buildTree(ll* arr, node * tree,ll l, ll r, ll i)
{
    if(l==r)
    {
        tree[i].mx = arr[l];
        tree[i].smx = INT_MIN;
        return;
    }
    
    ll mid = (l+r)/2;
    buildTree(arr,tree,l,mid,2*i);
    buildTree(arr,tree,mid+1,r,2*i+1);
    
    tree[i].mx = max(tree[2*i].mx,tree[2*i+1].mx);
    tree[i].smx = min(max(tree[2*i].mx,tree[2*i+1].smx),max(tree[2*i+1].mx,tree[2*i].smx));
    return;
}

void updateTree(ll * arr, node * tree,ll l, ll r, ll i, ll index, ll val)
{
    if(l==r)
    {
        arr[index] = val;
        tree[i].mx = val;
        return;
    }
    
    ll mid = (l+r)/2;
    if(index>mid)
    {
        updateTree(arr,tree,mid+1,r,2*i+1,index,val);
    }
    
    else
    {
        updateTree(arr,tree,l,mid,2*i,index,val);
    }
    
    tree[i].mx = max(tree[2*i].mx,tree[2*i+1].mx);
    tree[i].smx = min(max(tree[2*i].mx,tree[2*i+1].smx),max(tree[2*i+1].mx,tree[2*i].smx));
    return;
    
}

node queryTree(ll * arr, node * tree,ll s,ll e, ll i, ll l, ll r)
{
    
    if(s>r || e<l)
    {
        node ans;
        ans.mx = INT_MIN;
        ans.smx = INT_MIN;
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
    ans.mx = max(lans.mx,rans.mx);
    ans.smx = min(max(lans.mx,rans.smx),max(rans.mx,lans.smx));
    
    return ans;
}

int main() {

    // Write your code here
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    node * tree = new node[3*n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    buildTree(arr,tree,0,n-1,1);
//    for(int i=1;i<2*n;i++)cout<<tree[i].mx<<" "<<tree[i].smx<<endl;
    
    int q;
    cin>>q;
    
    for(int i=0;i<q;i++)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            ll l,r;
            cin>>l>>r;
            if(l==r)
            {
                ll x = l-1;
                 cout<<arr[x]<<endl;
                 continue;
            }
            node ans = queryTree(arr,tree,0,n-1,1,l-1,r-1);
            cout<<ans.mx+ans.smx<<endl;
        }
        
        else
        {
            ll index,val;
            cin>>index>>val;
            updateTree(arr,tree,0,n-1,1,index-1,val);
        }
    }
}