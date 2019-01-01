#include<bits/stdc++.h>

using namespace std;

struct edge{
	int source;
	int dest;
	int weight;
};

void bellman(vector<edge> & edges, int * dis,int n,int source)
{
	dis[source]=0;
	for(int i=0;i<n;i++)
	{
		if(i==source)continue;
		dis[i] = INT_MAX;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			//cout<<"Source:"<<edges[j].source<<" "<<"Dest:"<<edges[j].dest
			if(dis[edges[j].source]!=INT_MAX && dis[edges[j].source]+edges[j].weight<dis[edges[j].dest])
			{
				dis[edges[j].dest] = dis[edges[j].source]+edges[j].weight;
			}
		}

		/*
		for(int i=0;i<n;i++)
		{
			cout<<i<<":"<<dis[i]<<endl;
		}
		cout<<endl;
		*/
	}

}

/*
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
3 1 1
1 3 2
1 4 2
4 3 -3
*/
int main()
{
	int n,e;
	cin>>n>>e;

	vector<edge> edges;

	for(int i=0;i<e;i++)
	{
		edge current;
		cin>>current.source>>current.dest>>current.weight;
		edges.push_back(current);
	}
	int source;
	cout<<"Source:";
	cin>>source;
	int * dis = new int[n];
	bellman(edges,dis,n,source);

	for(int i=0;i<n;i++)
	{	
		if(dis[i]==INT_MAX)
		{
			cout<<i<<":"<<"No path"<<endl;
		} else {
			cout<<i<<":"<<dis[i]<<endl;	
		}
		
	}
}