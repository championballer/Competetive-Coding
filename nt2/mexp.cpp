#include<bits/stdc++.h>

using namespace std;

int mexp(int a, int b,int mod)
{	
	//O(b) time complexity since we are making two calls for half size
	if(b==0)return 1;
	
	if(b%2==0)//b is even
	{
		return ((long long) mexp(a,b/2,mod)*mexp(a,b/2,mod))%mod;
	}		
	
	else
	{
		return ((long long)a*((long long)mexp(a,b/2,mod)*mexp(a,b/2,mod))%mod)%mod;
	}
}

int psimple(int a,int b,int mod)
{
	//log(b) time complexity, recursive solution
	if(b==0)return 1;
	
	if(b%2==0)
	{
		return psimple(((long long)a*a)%mod,b/2,mod);
	}
	
	else
	{
		return ((long long)a*psimple(((long long)a*a)%mod,b/2,mod))%mod;
	}
	
}
int mexpit(int a,int b,int mod)
{	
	//log(b) time complexity, iterative solution
	if(b==0)return 1;
	int ans = 1;
	int current = a;
	while(b)
	{
		if(b&1)
		{
			ans=((long long)ans*current)%mod;
		}
		
		current = ((long long)current*current)%mod;
		b/=2;
	}
	return ans;
}

int main()
{
	int a;
	int b;
	int mod;
	cin>>a>>b>>mod;
	
	cout<<mexpit(a,b,mod)<<endl;
	cout<<mexp(a,b,mod)<<endl;
	cout<<psimple(a,b,mod)<<endl;
	/*int a = 45;
	while(a)
	{
		cout<<(a&1);
		a/=2;
	}
	
	cout<<endl;*/
}
