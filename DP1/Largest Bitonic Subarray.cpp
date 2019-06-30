#include<bits/stdc++.h>

int * lis(int * A, int n)
{
    int * dp = new int[n];
    dp[0] = 1;
    for(int i=1;i<n;i++)
    {
        int mx = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]>A[j])mx = max(mx,dp[j]);
        }
        dp[i] = mx+1;
    }
    
    return dp;
    
}

int longestBitonicSubarray(int *input, int n) {
		  	
    int * dp1 = lis(input,n);
    int * input2 = new int[n];
    for(int i=0;i<n;i++)input2[i] = input[n-1-i];
    int * dp2 = lis(input2,n);
    reverse(dp2,dp2+n);
    int mx = 0;
    for(int i=0;i<n;i++)
    {
        
        mx = max(mx,dp1[i]+dp2[i]-1);
    }
    
    return mx;
}

