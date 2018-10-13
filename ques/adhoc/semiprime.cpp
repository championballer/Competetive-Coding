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
	cout<<semiprime(8)<<endl;
	cout<<semiprime(15)<<endl;	
}
