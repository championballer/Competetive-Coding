#include<bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        ull* size = new ull[n];
        ull* ef = new ull[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>size[i];
            cin>>ef[i];
        }
        sort(size,size+n);
        sort(ef,ef+n);
        int mx = 0;
        int count = 0;
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(ef[i]<size[j])
            {
                count++;
                if(count>mx)mx = count;
                i++;
            }
            
            else
            {
                count--;
                if(count<0)count=0;
                j++;
            }
        }
        
        cout<<mx<<endl;
    }
}
