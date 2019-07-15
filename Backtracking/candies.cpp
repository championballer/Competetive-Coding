#include<bits/stdc++.h>
using namespace std;

bool poss(long long* arr, int n,long long middle,long long k)
{
	long long * aux = new long long[n];
	for(int i=0;i<n;i++)aux[i] = arr[i];
  	int count = k;
 	for(int i=0;i<n;i++)
   	 {
     		 while(aux[i]>=middle)
      		{
        		count--;
        		aux[i]-=middle;
        		if(count==0)return true;
      		}
    	}
  
  	return false;
}

int main() {

	// Write your code here
  	int t;
  	cin>>t;
  
  	while(t)
    {
      t--;
      
      int n;
      cin>>n;
      long long k;
      cin>>k;
      
      long long * arr = new long long[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      
      sort(arr,arr+n);
    
      long long low = 0;
      long long high = arr[n-1];
      long long ans = 0;
      while(low<=high)
      {
        long long middle = low + (high-low)/2;
        cout<<middle<<":"<<poss(arr,n,middle,k)<<endl;
        if(poss(arr,n,middle,k))
        {
          ans = middle;
          low = middle+1;
        }
        
        else
        {
          high = middle-1;
        }
      }
      
      cout<<ans<<endl;
    }
}
