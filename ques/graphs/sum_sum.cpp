#include<bits/stdc++.h>

using namespace std;

struct triplet
{
  int q;
  int f;
  int cost;
};

triplet getcost(vector<int>* edges, int n,bool * visited,int start,vector<int>&val)
{
    if(edges[start].size()==0)
    {
        triplet cans;
        cans.q = val[start];
        cans.f = cans.q;
        cans.cost = cans.f;
        return cans;
    }
    
    triplet cans;
    cans.q = 0;
    cans.f = 0;
    cans.cost = 0;
    
    for(int i=0;i<edges[start].size();i++)
    {
    	
        if(!visited[edges[start][i]])
        {
            visited[edges[start][i]]=true;
            triplet sans = getcost(edges,n,visited,edges[start][i],val);
            cans.q += sans.q;
            cans.f += sans.f;
            cans.cost += sans.f;    
        }
        
        
        
    }
    
    cans.q += val[start];
    cans.f += cans.q;
    cans.cost += cans.f;
    return cans;
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> val(n);
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    
    vector<int>* edges = new vector<int>[n];
    for(int i=0;i<n-1;i++)
    {
        int f,s;
        cin>>f>>s;
        
        edges[f-1].push_back(s-1);
        edges[s-1].push_back(f-1);
    }
    
    int mn = INT_MAX;
    int mnNode = -1;
    
    for(int i=0;i<n;i++)
    {
        bool* visited = new bool[n];
        memset(visited,false,sizeof(bool)*n);
        visited[i] = true;
        triplet fans = getcost(edges,n,visited,i,val);
        if(fans.cost<mn)
        {
            mn = fans.cost;
            mnNode = i;
        }
    }
    
    cout<<mnNode+1<<" "<<mn<<endl;
}
