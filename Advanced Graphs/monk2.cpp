#include<bits/stdc++.h>

using namespace std;

int path(vector<int>* edges, int n)
{
	bool * visited = new bool[n];
	memset(visited,false,sizeof(bool)*n);
	
	queue<int> pendingNodes;
	pendingNodes.push(0);
	visited[0]=true;
	int count = 0;
	while(!pendingNodes.empty())
	{
	    queue<int> pendingLevels;
	    while(!pendingNodes.empty())
	    {
	        pendingLevels.push(pendingNodes.front());
	        pendingNodes.pop();
	    }
	    
	    while(!pendingLevels.empty())
	    {
	        int front = pendingLevels.front();
	        pendingLevels.pop();
	        if(front==n-1)return count;
	        for(int i=0;i<edges[front].size();i++)
	        {
	            if(!visited[edges[front][i]])
	            {
	                pendingNodes.push(edges[front][i]);
	                visited[edges[front][i]]=true;
	            }
	        }
	    }
	    
	    count++;
	}
	
	return -1;
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
