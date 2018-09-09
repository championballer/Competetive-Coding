#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,x,s;
		cin>>n>>x>>s;
		
		for(int i=0;i<s;i++)
		{
			int f,s;
			cin>>f>>s;
			if(f==x)x=s;
			else if(s==x)x=f;
		}
		
		cout<<x<<endl;
	}
}
