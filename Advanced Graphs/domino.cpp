#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>* edges, int n, bool* visited, stack<int>& finished, int start)
{
  visited[start]=true;
  for(int i=0;i<edges[start].size();i++)
  {
    if(!visited[edges[start][i]])
    {
      dfs(edges,n,visited,finished,edges[start][i]);
    }
  }
  finished.push(start);
}

void dfs2(vector<int>* edges, int n,bool * visited,int start)
{
  	visited[start]=true;
  	for(int i=0;i<edges[start].size();i++)
    {
      if(!visited[edges[start][i]])
      {
        dfs2(edges,n,visited,edges[start][i]);
      }
    }
}

int getpush(vector<int>* edges, int n)
{
  stack<int> finished;
  bool* visited = new bool[n];
  memset(visited,0,sizeof(bool)*n);
  
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      	dfs(edges,n,visited,finished,i);
    }
  }
  
  memset(visited,0,sizeof(bool)*n);
  
  int count = 0;
  while(!finished.empty())
  {
    int front = finished.top();
    finished.pop();
    if(!visited[front])
    {
      count++;
      dfs2(edges,n,visited,front);
    }
  }
  
  return count;
}

int main()
{
	//code
  
  	int t;
  	cin>>t;
  
  	while(t--)
    {
      int n,e;
      cin>>n>>e;
      vector<int>* edges = new vector<int>[n];
      
      for(int i=0;i<e;i++)
      {
        int f,s;
        cin>>f>>s;
        
        edges[f-1].push_back(s-1);
      }
      
      int comp = getpush(edges,n);
      cout<<comp<<endl;
    }
	return 0;
}

