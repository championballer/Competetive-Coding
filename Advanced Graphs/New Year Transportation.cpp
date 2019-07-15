#include<bits/stdc++.h>
using namespace std;
int main()
{
	//code
    int n,index;
    cin>>n>>index;
    
    vector<int> arr(n-1,0);
    for(int i=0;i<n-1;i++)cin>>arr[i];
    
    int i = 0;
    while(i<=index-1)
    {
        if(i==index-1)
        {
            cout<<"YES"<<endl;
            break;
        }
        else
        {
            i+=arr[i];
        }
    }
    
    if(i>index-1)cout<<"NO"<<endl;
	return 0;
}
