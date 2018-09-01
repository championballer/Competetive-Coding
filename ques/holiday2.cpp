#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<char> arr(n);
    
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    
    long long count = 0;
    for(int i=0;i<=n-4;i++)
    {
        char current = arr[i];
	    int mark = 0;
        for(int j=i+2;j<n-1;j++)
        {
            	
            if(arr[j]==current)
            {
            	int * visited = new int[128];
            	memset(visited,0,sizeof(int)*128);
                mark = j;
                for(int k=i+1;k<mark;k++)
        	    {
            		char tomatch = arr[k];
            		int counts = 0;
            		if(visited[tomatch]==0)
            		{	
            			for(int q=mark+1;q<n;q++)
                		{
                			if(arr[q]==tomatch)counts++;
                		}
                		visited[tomatch]=counts;
                		
            			
            		}
                	count+=visited[tomatch];
            		
        	}
        	
        	delete [] visited;
            }
            
        }
        
        if(mark==0)continue;
        
        
    }
    
    cout<<count<<endl;

}
