#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int>* edges = new vector<int>[n];
    
    for(int i=0;i<n-1;i++)
    {
        int f,s;
        cin>>f>>s;
        
        edges[f-1].push_back(s-1);
        edges[s-1].push_back(f-1);
    }
    
    int g;
    cin>>g;
    
    unordered_map<int,bool> ourmap;
    for(int i=0;i<g;i++)
    {
        int city;
        cin>>city;
        
        ourmap.insert(make_pair(city,true));
    }
    
    bool* visited = new bool[n];
    memset(visited,false,sizeof(bool)*n);
    queue<int> pendingNodes;
    visited[0] = true;
    pendingNodes.push(0);
    vector<int> current;
    while(!pendingNodes.empty())
    {
        queue<int> pendingLevels;
        while(!pendingNodes.empty())
        {
            pendingLevels.push(pendingNodes.front());
            pendingNodes.pop();
        }
        
        
        while(!pendingLevels.empty())
        {
            int front = pendingLevels.front();
            pendingLevels.pop();
            if(ourmap.count(front))
            {
                current.push_back(front);
            }
            
            for(int i=0;i<edges[front].size();i++)
            {
                if(!visited[edges[front][i]])
                {
                    pendingNodes.push(edges[front][i]);
                    visited[edges[front][i]]=true;
                }
            }
            
        }
        
        if(current.size()!=0)
        {
            break;
        }
        
    }
    
    sort(current.begin(),current.end());

    cout<<current[0]-1<<endl;
}
