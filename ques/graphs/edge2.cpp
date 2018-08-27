#include<bits/stdc++.h>

using namespace std;

bool ** edges = new bool*[1000];

int main()
{
    int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
	    edges[i] = new bool[n];
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
		
		if(edges[f-1][s-1])
		{
			cout<<"YES"<<endl;
		}
		
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
