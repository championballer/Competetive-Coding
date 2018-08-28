#include<bits/stdc++.h>

using namespace std;

vector<int> weights;
vector<int>* edges = new vector<int>[1000];

bool isCompare(int i1,int i2)
{
    return weights[i1]>=weights[i2];
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    weights.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }

    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f-1].push_back(s-1);
        edges[s-1].push_back(f-1);
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
        cout<<edges[i][k-1]+1<<endl;
    }
}
