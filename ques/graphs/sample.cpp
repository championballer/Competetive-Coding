#include<bits/stdc++.h>

using namespace std;

bool check(int f,int s,int * parent)
{
	int pf = parent[f];
	int ps = parent[s];
	while(pf!=parent[pf])
	{
		pf = parent[pf];
	}
	
	while(ps!=parent[ps])
	{
		ps = parent[ps];
	}
	
	if(pf==ps)return true;
	else return false;
}

int main()
{
	int * parent = new int[5];
	
	parent[0] = 1;
	parent[1] = 1;
	parent[2] = 2;
	parent[3] = 2;
	parent[4] = 1;
	
	cout<<check(0,1,parent)<<endl;
	cout<<check(0,2,parent)<<endl;
	cout<<check(0,4,parent)<<endl;
}

