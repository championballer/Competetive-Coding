#include<bits/stdc++.h>

using namespace std;

/*
20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2


*/
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
    
    int level;
    cin>>level;
    bool * visited = new bool[n];
    memset(visited,false,sizeof(bool)*n);
    
    queue<int> pendingNodes;
    pendingNodes.push(0);
    visited[0] = true;
    int x = 1;
    while(!pendingNodes.empty())
    {
        if(x==level)
        {
            int count=0;
            while(!pendingNodes.empty())
            {
                count++;
                pendingNodes.pop();
            }
            cout<<count<<endl;
            break;
        }
        queue<int> pendingLevels;
        while(!pendingNodes.empty())
        {
            int front = pendingNodes.front();
            pendingNodes.pop();
            pendingLevels.push(front);
        }
        
        while(!pendingLevels.empty())
        {
            int front = pendingLevels.front();
            pendingLevels.pop();
            for(int i=0;i<edges[front].size();i++)
            {
                if(!visited[edges[front][i]])
                {
                    pendingNodes.push(edges[front][i]);
                    visited[edges[front][i]]=true;
                }
            }    
        }
        
        
        x++;
    }
}
