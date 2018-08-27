#include<bits/stdc++.h>

using namespace std;

/*
	We find the connected components and for each component we check the
	set of elements, if the set of elements for all components are good, then
	we can safely print yes else we print no.

*/

void dfs(vector<int>* edges, int n,int start,unordered_set<int> * component,bool * visited)
{
	visited[start] = true;
	component->insert(start);
	
	for(int i=0;i<edges[start].size();i++)
	{
		if(!visited[(edges[start][i])])
		{
			dfs(edges,n,edges[start][i],component,visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getComp(vector<int>* edges, int n)
{
	bool * visited = new bool[n];
	memset(visited,false, sizeof(bool)*n);
	
	unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
	for(int i=0;i<n;i++)
	{
		unordered_set<int>* component = new unordered_set<int>();
		if(!visited[i])
		{
			dfs(edges,n,i,component,visited);
			components->insert(component);
		}
	}
	
	return components;
	
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
		
		vector<int> p(n),q(n);
		
		for(int i=0;i<n;i++)
		{
			int current;
			cin>>current;
			p[i] = current-1;
		}

		for(int i=0;i<n;i++)
		{
			int current;
			cin>>current;
			q[i] = current-1;
		}
		
		
		vector<int> * edges = new vector<int>[n];
		for(int i=0;i<m;i++)
		{
			int f,s;
			cin>>f>>s;
			
			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);
		}
		
		unordered_set<unordered_set<int>* > * components = getComp(edges,n);
		unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
		
		
		/*while(it1!=components->end())
		{
			unordered_set<int> * component = *it1;
			unordered_set<int>:: iterator it2 = component->begin();
			while(it2!=component->end())
			{
				cout<<*it2+1<<" ";
				it2++;
			}
			
			cout<<endl;
			it1++;
		}*/	
		
		it1 = components->begin();
		int flag = 0;
		while(it1!=components->end())
		{
			
			unordered_set<int>* component = *it1;
			
			unordered_set<int>:: iterator it2 = component->begin();
			unordered_map<int,bool> ourmap;
			vector<int> check;
			while(it2!=component->end())
			{
				int index = *it2;
				//cout<<index<<" "<<p[index]<<" "<<q[index]<<endl;
				ourmap.insert(make_pair(p[index],false));
				check.push_back(q[index]);
				it2++;
			}
			//cout<<check.size()<<endl;
			for(int i=0;i<check.size();i++)
			{
				//cout<<check[i]<<endl;
				if(!ourmap.count(check[i]))
				{
					cout<<"No"<<endl;
					flag = 1;
					break;
				}
			}
			it1++;
			if(flag==1)break;
		}	
		
		if(!flag)cout<<"Yes"<<endl;
		
		
		
		
	}
}
