#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>* edges,int n,int start,bool * visited,unordered_set<int> * component)
{
	visited[start] = true;
	component->insert(start);
	for(int i=0;i<edges[start].size();i++)
	{
		if(!visited[(edges[start][i])])
		{
			
			dfs(edges,n,edges[start][i],visited,component);
		}
	}
}

unordered_set<unordered_set<int>*>* getComp(vector<int>* edges,int n)
{
	bool * visited = new bool[n];
	memset(visited,false,sizeof(bool)*n);
	
	unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
	for(int i=0;i<n;i++)
	{
		unordered_set<int> * component = new unordered_set<int>();
		if(!visited[i])
		{
			dfs(edges,n,i,visited,component);
			components->insert(component);
		}
		
	}
	
	return components;
}

int main()
{
	int n;//vertices
	cin>>n;
	
	vector<int> * edges = new vector<int>[n];//array of vectors
	
	int m;//edges
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		int j,k;
		cin>>j>>k;
		
		edges[j-1].push_back(k-1);
		edges[k-1].push_back(j-1);
	}
	
	unordered_set<unordered_set<int>*>* components = getComp(edges,n);
	unordered_set<unordered_set<int>*>:: iterator it1;
	it1 = components->begin();
	while(it1!=components->end())
	{
		unordered_set<int>* component = *it1;
		unordered_set<int>:: iterator it2;
		it2 = component->begin();
		while(it2!=component->end())
		{
			cout<<*it2+1<<" ";
			it2++;
		}
		it1++;
		cout<<endl;
	}
	
}
