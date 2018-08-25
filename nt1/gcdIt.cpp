#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	if(b>a)return gcd(b,a);
	
	int tb = b;
	int ta = a;
	
	while(tb)
	{
		int temp = ta;
		ta = tb;
		tb = temp%tb;
	}
	
	return ta;
}

int main()
{	
	int a;
	int b;
	cin>>a>>b;
	
	cout<<gcd(a,b)<<endl;
}
