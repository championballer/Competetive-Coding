#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll helper(int * arr, int n)
{
    ll * dp = new ll[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    
    for(int i=1;i<n;i++)
    {
        dp[i+1] = max(dp[i],dp[i-1]+arr[i]);
    }
    
    return dp[n];
}

int main()
{
    int t;
    cin>>t;
    
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        
        int * arr = new int[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        
        ll ans = helper(arr,n);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
