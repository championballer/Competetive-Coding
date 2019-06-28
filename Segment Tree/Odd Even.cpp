#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100004];
ll tree[4*100004];

void buildTree(ll l,ll r, ll i)
{
    if(l==r)
    {
        tree[i] = arr[l];
        return;
    }
    
    ll mid = (l+r)/2;
    buildTree(l,mid,2*i);
    buildTree(mid+1,r,2*i+1);
    
    tree[i] = tree[2*i]+tree[2*i+1];
}

void updateTree(ll l, ll r, ll i, ll index,ll val)
{
    //cout<<l<<" "<<r<<" "<<tree[i]<<endl;
    if(l==r)
    {
        arr[index] = 1-(val%2);
        tree[i] = arr[index];
        return;
    }
    
    ll mid = (l+r)/2;
    if(index>mid)
    {
        updateTree(mid+1,r,2*i+1,index,val);
    }
    
    else
    {
        updateTree(l,mid,2*i,index,val);
    }
    
    tree[i] = tree[2*i]+tree[2*i+1];
}

ll query(ll s,ll e, ll i, ll l, ll r)
{
    if(s>r || e<l)return 0;
    if(s>=l && e<=r)return tree[i];
    
    ll mid = (s+e)/2;
    ll lans = query(s,mid,2*i,l,r);
    ll rans = query(mid+1,e,2*i+1,l,r);
    
    return lans+rans;
}
int main() {
    
    // Write your code here
    
    ll n;
    cin>>n;
    
    for(ll i=0;i<n;i++)
    {
        ll c;
        cin>>c;
        arr[i] = 1-(c%2);
    }
    buildTree(0,n-1,1);
    
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        ll t;
        cin>>t;
        
        if(t==0)
        {
            ll index, val;
            cin>>index>>val;
            updateTree(0,n-1,1,index-1,val);
        }
        
        else if(t==1)
        {
            ll l,r;
            cin>>l>>r;
            ll ans = query(0,n-1,1,l-1,r-1);
            cout<<ans<<endl;
        }
        
        else if(t==2)
        {
            ll l,r;
            cin>>l>>r;
            
            cout<<(r-l+1)-query(0,n-1,1,l-1,r-1)<<endl;
        }
        
        // for(int i=1;i<2*n;i++)cout<<tree[i]<<" ";
        // cout<<endl;
    }

    return 0;
}