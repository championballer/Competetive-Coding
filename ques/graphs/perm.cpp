#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>* edges, int n,bool * visited,unordered_set<int>* comp,int start)
{
    visited[start] = true;
    comp->insert(start);
    
    for(int i=0;i<edges[start].size();i++)
    {
        if(!visited[edges[start][i]])
        {
            dfs(edges,n,visited,comp,edges[start][i]);
        }
    }
}

unordered_set<unordered_set<int>*>* getcomp(vector<int>* edges, int n)
{
    unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
    bool * visited = new bool[n];
    memset(visited,false,sizeof(bool)*n);
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int>* comp = new unordered_set<int>();
            dfs(edges,n,visited,comp,i);
            components->insert(comp);
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
        
        vector<int> p(n);
        vector<int> q(n);
        vector<int> * edges = new vector<int>[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>q[i];
        }
        
        
        for(int i=0;i<m;i++)
        {
            int f,s;
            cin>>f>>s;
            edges[f-1].push_back(s-1);
            edges[s-1].push_back(f-1);
        }
        
        unordered_set<unordered_set<int>*>* components = getcomp(edges,n);
        
        unordered_set<unordered_set<int>*>::iterator it1;
        it1 = components->begin();
        int flag = 0;
        while(it1!=components->end())
        {
            unordered_set<int>* comp = *it1;
            unordered_set<int>::iterator it2;
            it2 = comp->begin();
            unordered_map<int,bool> ourmap;
            vector<int> check;
            while(it2!=comp->end())
            {
                int index = *it2;
                ourmap.insert(make_pair(p[index],false));
                check.push_back(q[index]);
                it2++;
            }
            
            for(int i=0;i<check.size();i++)
            {
                if(!ourmap.count(check[i]))
                {
                    flag = 1;
                    break;
                }
            }
            
            
            if(flag)break;
            it1++;
        }
        
        if(!flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
