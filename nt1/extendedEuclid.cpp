#include<bits/stdc++.h>

using namespace std;

struct triplet
{
	int gcd;
	int x;
	int y;
};

triplet extendedgcd(int a, int b)
{

	if(b>a)return extendedgcd(b,a);
	if(b==0)
	{
		triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	
	triplet sans = extendedgcd(b,a%b);
	triplet ans;
	
	ans.gcd = sans.gcd;
	ans.x = sans.y;
	ans.y = sans.x - (a/b)*sans.y;
	
	return ans;
}
int main()
{
	int a,b;
	cin>>a>>b;
	
	triplet ans = extendedgcd(a,b);
	cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
}
