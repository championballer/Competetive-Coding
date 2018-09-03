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
	else
	{
	  parent[f] = ps;
	  return false;
	}
}

vector<pair<int,pair<int,int> > > kruskal(vector<pair<int,pair<int,int> > >& edges,int n,int * parent)
{
	vector<pair<int,pair<int,int> > > output;
	int count = 0;
	for(int i=0;i<edges.size();i++)
	{
		int f = edges[i].second.first;
		int s = edges[i].second.second;
		int w = edges[i].first;
		if(!check(f,s,parent))
		{
			output.push_back(make_pair(w,make_pair(f,s)));
			count++;
			if(count==n-1)break;
		}
	}
	return output;
} 

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,pair<int,int> > > edges;
	
	for(int i=0;i<m;i++)
	{
		int f,s,w;
		cin>>f>>s>>w;
		
		edges.push_back(make_pair(w,make_pair(f-1,s-1)));
	}
	
	sort(edges.begin(),edges.end());
	
	/*cout<<endl;
	for(int i=0;i<m;i++)
	{
		int f = edges[i].second.first;
		int s = edges[i].second.second;
		int w = edges[i].first;
		cout<<f+1<<" "<<s+1<<" "<<w<<endl;
	}*/
	
	int * parent = new int[n];
	for(int i=0;i<n;i++)parent[i]=i;
	
	
	vector<pair<int,pair<int,int> > > mst = kruskal(edges,n,parent);
	
	int tw = 0;
	for(int i=0;i<mst.size();i++)
	{
		int f,s,w;
		f = mst[i].second.first;
		s = mst[i].second.second;
		w = mst[i].first;
		tw+=w;
		//cout<<f+1<<" "<<s+1<<" "<<w<<endl;
	}
	
	cout<<tw<<endl;
	return 0;
}
