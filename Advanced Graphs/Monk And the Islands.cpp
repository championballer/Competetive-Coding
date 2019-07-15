#include<bits/stdc++.h>

using namespace std;

int path(vector<int>* edges, int n)
{
	bool * visited = new bool[n];
	memset(visited,false,sizeof(bool)*n);
	
	queue<pair<int,int> > pendingNodes;
	pendingNodes.push(make_pair(0,0));
	
	
	while(!pendingNodes.empty())
	{
		pair<int,int> front = pendingNodes.front();
		pendingNodes.pop();
		int f = front.first;
        visited[f] = true;
        int s = front.second;
		if(f==n-1)return s;
		for(int i=0;i<edges[f].size();i++)
		{
            int x = edges[f][i];
			if(!visited[x])
			{
				pendingNodes.push(make_pair(x,s+1));
			}
		}		
	}
    
    return 0;
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