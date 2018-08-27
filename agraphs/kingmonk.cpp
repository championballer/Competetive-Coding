#include<bits/stdc++.h>

#define ull unsigned long long
#define pb push_back

using namespace std;

void dfs(vector<int>* edges,int n,bool * visited,unordered_set<int>* comp, int ci)
{
    visited[ci] = true;
    comp->insert(ci);
    
    for(int i=0;i<edges[ci].size();i++)
    {
        if(!visited[edges[ci][i]])
        {
            dfs(edges,n,visited,comp,edges[ci][i]);
        }
    }
}

unordered_set<unordered_set<int>*>* getcomp(vector<int>* edges,int n)
{
    unordered_set<unordered_set<int>*>* comps = new unordered_set<unordered_set<int>*>();
    bool * visited = new bool[n];
    memset(visited,false,sizeof(bool)*n);
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int>* comp = new unordered_set<int>();
            dfs(edges,n,visited,comp,i);
            comps->insert(comp);
        }
    }
    
    return comps;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>* edges = new vector<int>[n];
        int * bana = new int[n];
        for(int i=0;i<m;i++)
        {
            int f,s;
            cin>>f>>s;
            edges[f-1].pb(s-1);
            edges[s-1].pb(f-1);
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>bana[i];
        }
        
        unordered_set<unordered_set<int>*>* comps = getcomp(edges,n);
        unordered_set<unordered_set<int>*> :: iterator it1;
        it1 = comps->begin();
        ull mx=0;
        while(it1!=comps->end())
        {
            unordered_set<int>* comp = *it1;
            unordered_set<int>::iterator it2;
            it2 = comp->begin();
                ull sum = 0;
                while(it2!=comp->end())
                {
                    int index = *it2;
                    sum+=bana[index];
                    it2++;
                }
                
                if(sum>mx)mx = sum;
            it1++;
        }
        cout<<mx<<endl;
    }
}
