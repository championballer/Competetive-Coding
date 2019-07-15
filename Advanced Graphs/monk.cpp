#include<bits/stdc++.h>

using namespace std;

int path(vector<int>* edges, int n)
{
	bool * visited = new bool[n];
	memset(visited,false,sizeof(bool)*n);
	
	queue<int> pendingNodes;
	pendingNodes.push(0);
	visited[0] = true;
	unordered_map<int,int> ourmap;
	ourmap.insert(make_pair(0,-1));
	while(!pendingNodes.empty())
	{
		int front = pendingNodes.front();
		pendingNodes.pop();
		
		if(front==n-1)break;
		for(int i=0;i<edges[front].size();i++)
		{
			if(!visited[(edges[front][i])])
			{
				visited[(edges[front][i])] = true;
				pendingNodes.push(edges[front][i]);
				ourmap.insert(make_pair(edges[front][i],front));
			}
		}		
	}
	
	int count = 0;
	int current = n-1;
	/*vector<int> apath;
	apath.push_back(current);*/
	
	while(current!=0)
	{
		current = ourmap[current];
		count++;
		//apath.push_back(current);
	}
	
	count++;
	return count;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int m;
		cin>>m;
		
		vector<int>* edges = new vector<int>[n];
		
		for(int i=0;i<m;i++)
		{
			int f,s;
			cin>>f>>s;
			
			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);	
		}
		
		int ans = path(edges,n);
		cout<<ans<<endl;
	}
}
