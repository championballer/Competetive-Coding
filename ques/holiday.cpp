#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<char> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int count = 0;
    for(int i=0;i<=n-4;i++)
    {
        char current = arr[i];
	int mark = 0;
        for(int j=i+2;j<n-1;j++)
        {
            if(arr[j]==current)
            {
                mark = j;
                cout<<i<<" "<<mark<<endl;
                for(int k=i+1;k<mark;k++)
        	{
            		char tomatch = arr[k];
            		for(int m=mark+1;m<n;m++)
            		{
                		if(arr[m]==tomatch)count++;
            		}
        	}
            }
            
        }
        
        if(mark==0)continue;
        
        
    }
    
    cout<<count<<endl;

}
