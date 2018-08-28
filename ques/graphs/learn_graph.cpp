#include<bits/stdc++.h>

using namespace std;

bool isCompare(pair<int,int> c1,pair<int,int> c2)
{
    if(c1.second==c2.second)
    {
        return c1.first>c2.first;
    }
    return c1.second>c2.second;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<int> weights(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    
    vector<pair<int,int> >* edges = new vector<pair<int,int> >[n];
    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f-1].push_back(make_pair(s-1,weights[s-1]));
        edges[s-1].push_back(make_pair(f-1,weights[f-1]));
    }
    
    for(int i=0;i<n;i++)
    {
        sort(edges[i].begin(),edges[i].end(),isCompare);
    }
    
    for(int i=0;i<n;i++)
    {
        if(k-1>edges[i].size())
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<edges[i][k-1].first+1<<endl;
    }
}
