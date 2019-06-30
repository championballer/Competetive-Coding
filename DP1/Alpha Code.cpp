#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

bool check(string s)
{
    if(s.length()==1 && s[0]!='0')return true;
    if(s[0]!='1' && s[0]!='2')return false;
    else
    {
        
        if(s[0]=='1')return true;
        else if(s[0]=='2')
        {
            if(s[1]>='0' && s[1]<='6')return true;
        }
        else return false;
    }
    
    return false;
    
}

ll helper(string & s)
{
    ll * arr = new ll[s.length()+1];
    memset(arr,0,sizeof(ll)*s.length()+1);
    arr[s.length()] = 1;
    if(check(s.substr(s.length()-1,1)))arr[s.length()-1] = 1;
    else arr[s.length()-1] = 0;
    
    for(int i=s.length()-2;i>=0;i--)
    {
        
        if(check(s.substr(i,1)))
        {
            arr[i] = ((arr[i]%MOD)+(arr[i+1]%MOD))%MOD;
        }
        
        if(check(s.substr(i,2)))
        {
            arr[i] = ((arr[i]%MOD)+(arr[i+2]%MOD))%MOD;
        }
    }
    
    return arr[0]%MOD;
}

int main()
{
    string s;
    cin>>s;
    ll ans  = 0;
    while(s!="0")
    {
        ans = helper(s);
        cout<<ans<<endl;
        cin>>s;
    }
    return 0;
}
