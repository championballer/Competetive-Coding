#include<bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

struct treeNode
{
  int data;
  int rank;
  vector<treeNode*> children;
};

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        
        ull* ranks = new ull[n];
        for(int i=0;i<n;i++)
        {
            cin>>ranks[i];
        }
        
        unordered_map<int,vector<int> > ourmap;
        for(int i=0;i<n-1;i++)
        {
            int s,e;
            cin>>s>>e;
            
            ourmap[s].push_back(e);
            if(!ourmap.count(e))
            {
            	ourmap[e].push_back(0);
            }
        }
        
        unordered_map<int,vector<int> >::iterator it;
        it = ourmap.begin();
        
        while(it!=ourmap.end())
        {
        	cout<<it->first<<" ";
        	for(int i=0;i<it->second.size();i++)
        	{
        		if(it->second[i]==0)continue;
        		cout<<it->second[i]<<" ";
        	}
        	cout<<endl;
        	it++;
        	
        }
        
        bool* visited = new bool[n+1];
        memset(visited,false,sizeof(bool)*n);
        
        it = ourmap.begin();
        while(it!=ourmap.end())
        {
        	for(int i=0;i<it->second.size();i++)
        	{
        		if(it->second[i]==0)continue;
        		visited[it->second[i]]=true;
        	}
        	it++;
        }
        int head = 0;
        for(int i=1;i<=n;i++)
        {
        	if(!visited[i])
        	{
        		head=i;
        		break;
        	}
        }
        
        cout<<head<<endl;
    }
}

