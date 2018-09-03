#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,pair<int,int> > >edges;
	for(int i=0;i<m;i++)
	{
		int f,s,w;
		cin>>f>>s>>w;
		
		edges.push_back(make_pair(w,make_pair(f,s)));
	}
}
