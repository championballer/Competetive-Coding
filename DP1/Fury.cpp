#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    int * dp = new int[1001];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=1001;i++)
    {
        int mn = INT_MAX;
        for(int j=1;j*j<=i;j++)
        {
            mn = min(dp[i-(j*j)]+1,mn);
        }
        
        dp[i] = mn;
    }
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        cout<<dp[n]<<endl;
    }
    return 0;
    
}
