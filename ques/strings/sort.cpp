#include<bits/stdc++.h>

bool compare(char c1,char c2)
{
    return c1>c2;
}

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        int f,s;
        cin>>f>>s;
        
        sort(str.begin()+f,str.begin()+s+1,compare);
        cout<<str<<endl;
    }
}
