#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int current;
        cin>>current;
        sum+=current;
    }
    
    if(sum/2==n-1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
