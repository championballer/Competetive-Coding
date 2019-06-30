#include<bits/stdc++.h>

int dp[10][1000];

int helper(vector<int> & den, int i, int value)
{
    if(value<0)return 0;
    if(i==den.size())return 0;
    if(dp[i][value]!=-1)return dp[i][value];
    if(value==0)return 1;
    
    int sans1 = helper(den,i,value-den[i]);
    int sans2 = helper(den,i+1,value);
    
    dp[i][value] = sans1+sans2;
    return dp[i][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    memset(dp,-1,sizeof(dp));
    vector<int> den(numDenominations,0);
    for(int i=0;i<numDenominations;i++)
    {
        den[i] = denominations[i];
        
    }
    
    return helper(den,0,value);
    


}
