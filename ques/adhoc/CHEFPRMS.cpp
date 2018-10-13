#include<bits/stdc++.h>

using namespace std;

bool semiprime(int n)
{
	int count = 0;
	
	for(int i=2;count<2 && i*i<=n;i++)
	{
		while(n%i==0)
		{
			n/=i;
			count++;
		}
	}
	
	if(n>1)count++;
	
	return count==2;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int flag = 0;
		for(int i=6;i<=n/2;i++)
		{
			if(semiprime(i) && semiprime(n-i))
			{
				
				flag=1;
				break;
			}
		}
		
		if(!flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}	
}
