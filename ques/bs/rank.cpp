#include<bits/stdc++.h>

using namespace std;

int bs(vector<int>& arr,int f)
{
    int low = 0;
    int high = arr.size()-1;
    
    while(low<=high)
    {
        int middle = low+((high-low)/2);
        if(arr[middle]==f)
        {
            return middle;
        }
        
        else if(arr[middle]>f)
        {
            high = middle-1;
        }
        
        else low = middle+1;
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr.begin(),arr.end());
    
    int q;
    cin>>q;
    
    for(int i=0;i<q;i++)
    {
        int f;
        cin>>f;
        
        cout<<bs(arr,f)+1<<endl;
    }
}
