#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void method1()
{
	int n;
    	cin>>n;
    
    	vector<int> * edges = new vector<int>[n];
    
    	int m;
    	cin>>m;
    	for(int i=0;i<m;i++)
    	{
        	int f,s;
        	cin>>f>>s;
        
        	edges[f-1].pb(s-1);
        	edges[s-1].pb(f-1);
    	}
    
   	int q;
    	cin>>q;
    
    	for(int i=0;i<q;i++)
    	{
        	int flag = 0;
        	int f,s;
        	cin>>f>>s;
        	for(int j=0;j<edges[f-1].size();j++)
        	{
            		if(edges[f-1][j]==s-1)
            		{
                		flag=1;
                		break;
            		}
        	}
        
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    	}

}

void method2()
{	
	int n;
	cin>>n;
	
	int ** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j] = 0;
		}
	}
	
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin>>f>>s;
		
		edges[f-1][s-1]=1;
		edges[s-1][f-1]=1;
	}
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		int f,s;
		cin>>f>>s;
		
		if(edges[f-1][s-1]==1)
		{
			cout<<"YES"<<endl;
		}
		
		else
		{
			cout<<"NO"<<endl;
		}
	}
}

int main()
{
        
}
