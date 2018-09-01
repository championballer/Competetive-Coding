#include<bits/stdc++.h>
#define MAX 100001
typedef long long ll;

using namespace std;

ll arr[MAX];

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int current;
        cin>>current;
        
        arr[current]++;
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            cout<<i<<endl;
    
            break;
        }
    }
    
}
