#include<bits/stdc++.h>

using namespace std;

class point
{
	public:
	int x;
	int y;
};

int fact(int n)
{
	int * dp = new int[n+1];
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		dp[i] = dp[i-1]*i;
	}
	
	return dp[n];
}

int pro(vector<int> sizes)
{
	int product = 1;
	for(int i=0;i<sizes.size();i++)
	{
		product*=fact(sizes[i]);
	}
	
	return product;
}

void dfs(vector<int>* edges, int p,int start, bool* visited, unordered_set<int>* component)
{
	visited[start] = true;
	component->insert(start);
	
	for(int i=0;i<edges[start].size();i++)
	{
		if(!visited[(edges[start][i])])
		{
			dfs(edges,p,edges[start][i],visited,component);
		}
	}
}

unordered_set<unordered_set<int>*>* getComp(vector<int>* edges, int p,vector<point> points)
{
	bool * visited = new bool[p];
	memset(visited,false,sizeof(bool)*p);
	
	unordered_set<unordered_set<int>*> * components = new unordered_set<unordered_set<int>*>();
	
	for(int i=0;i<p;i++)
	{
		unordered_set<int> * component = new unordered_set<int>();
		if(!visited[i])
		{
			dfs(edges,p,i,visited,component);
			components->insert(component);
		}
	}
	
	return components;

}

// 1 9 9 12 2 4 2 7 3 5 4 3 4 7 5 5 6 2 7 7 8 3 8 5 9 6 9 9 
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,p;
		cin>>n>>m>>p;
		
		vector<point> points;
		for(int i=0;i<p;i++)
		{
			point a;
			int x,y;
			cin>>x;
			cin>>y;
			a.x = x-1;
			a.y = y-1;
			points.push_back(a);
		}
		
		
		vector<int> * edges = new vector<int>[p];
		
		for(int i=0;i<points.size();i++)
		{
			point a = points[i];
			for(int j=0;j<points.size();j++)
			{
				if(i==j)continue;
				point b = points[j];
				int x1 = a.x;
				int x2 = b.x;
				int y1 = a.y;
				int y2 = b.y;
				
				if(abs(y2-y1)==1 && abs(x2-x1)==2)
				{
					edges[i].push_back(j);
				}
				
				else if(abs(y2-y1)==2 && abs(x2-x1)==1)
				{
					edges[i].push_back(j);
				}
				
			}
		}
		
		for(int i=0;i<p;i++)
		{
			//point a = points[i];
			//cout<<a.x<<" "<<a.y<<": ";
			cout<<i<<": ";
			for(int j=0;j<edges[i].size();j++)
			{
				//point a = points[edges[i][j]];
				//cout<<a.x<<" "<<a.y<<" ";
				cout<<edges[i][j]<<" ";
			}
			cout<<endl;
		}
		
		unordered_set<unordered_set<int>*>* components = getComp(edges,p,points);
		vector<int> sizes;
		unordered_set<unordered_set<int>*>::iterator it1;
		it1 = components->begin();
		while(it1!=components->end())
		{
			unordered_set<int>* component = *it1;
			unordered_set<int>:: iterator it2 = component->begin();
			sizes.push_back(component->size());
			while(it2!=component->end())
			{
				point a = points[*it2];
				cout<<a.x<<" "<<a.y<<endl;
				it2++;
				
			}
			cout<<endl;
			it1++;
		}
		
		for(int i=0;i<sizes.size();i++)
		{
			cout<<sizes[i]<<" ";
		}
		cout<<endl;
		
		cout<<pro(sizes)<<endl;
	}
}
