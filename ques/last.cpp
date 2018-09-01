#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int e;
    cin>>e;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int flag = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==e)
        {
            cout<<i+1<<endl;
            flag=1;
            break;
        }
    }
    
    if(!flag)cout<<-1<<endl;
}
