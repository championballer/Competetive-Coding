#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        unordered_set<int> cities;
        
        for(int i=0;i<n;i++)
        {
            int f,s;
            cin>>f>>s;
            cities.insert(f);
            cities.insert(s);
        }
        
        cout<<cities.size()<<endl;
    }
}
