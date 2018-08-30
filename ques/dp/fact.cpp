#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    vector<int> q;
    int max = INT_MIN;
    for(int i=0;i<t;i++)
    {
        int current;
        cin>>current;
        if(current>max)max = current;
        q.push_back(current);
    }
    
    long long * fact = new long long[max+1];
    int mod = 1000000007;
    fact[0] = 1;
    for(int i=1;i<=max;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    
    for(int i=0;i<q.size();i++)
    {
        cout<<fact[q[i]]<<endl;
    }
}
