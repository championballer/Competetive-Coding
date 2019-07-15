#include<bits/stdc++.h>

using namespace std;

int bt(int h)
{
	int * ans = new int[h+1];
	ans[0] = 0;
	ans[1] = 1;
	
	for(int i=2;i<=h;i++)
	{
		int x = ans[i-1];
		int y = ans[i-2];
		
		int mod = 1000000000+7;
		int t1 = (((long(x))%mod)*((x)%mod))%mod;
		int t2 = (((long(x))%mod)*((x)%mod))%mod;
		
		ans[i] = (t1+((2*(long(t2)%mod))%mod))%mod;
	}
	
	return ans[h];
}

int main()
{
	int h;
	cin>>h;
	
	cout<<bt(h)<<endl;	
}
