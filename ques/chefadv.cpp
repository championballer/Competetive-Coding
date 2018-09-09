#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		long long n,m,x,y;
		cin>>n>>m>>x>>y;
		
		if(n-1>=0 && m-1>=0 && !((n-1)%x) && !((m-1)%y))
		{
			cout<<"Chefirnemo"<<endl;
		}
		
		else if(n-2>=0 && m-2>=0 && !((n-2)%x) && !((m-2)%y))
		{
			cout<<"Chefirnemo"<<endl;	
		}
		
		else
		{
			cout<<"Pofik"<<endl;
		}
	}
}
