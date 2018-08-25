#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int A[], int n)
{
	// Write your code here.
  
  	if(n==0 || n==1)return 0;
  	
  	int middle = n/2;
  	int * arr = new int[n];
  	int * arr1 = new int[middle];
  	int * arr2 = new int[n-middle];
  
  	for(int i=0;i<middle;i++)
    	{
      		arr1[i] = A[i];
    	}
  	
  	for(int i=middle;i<n;i++)
    	{
      		arr2[i-middle] = A[i];
    	}
  
  	ll ans1 = solve(arr1,middle);
  	cout<<ans1<<endl;
  	
	ll ans2 = solve(arr2,n-middle);
	cout<<ans2<<endl;
	
  	
  	int i=0,j=0,current=0;
  	ll mergecount=0;
  	while(i<middle && j<n-middle)
    	{
      		if(arr1[i]<=arr2[j])
      		{
        		arr[current]=arr1[i];
        		current++;
        		i++;
        		continue;
      		}
      
      		else
      		{
        		arr[current]=arr2[j];
        		current++;
        		j++;
        		mergecount++;
        		continue;
      		}
    	}
  
  	while(i<middle)
    	{
      		arr[current]=arr1[i];
      		current++;
      		i++;
    	}
  
  	while(j<n-middle)
    	{
      		arr[current]=arr2[j];
      		current++;
      		j++;
    	}
  	
  	for(int i=0;i<n;i++)
    	{
      		A[i] = arr[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		cout<<A[i]<<" ";
    	}
    	cout<<endl;
  	cout<<mergecount<<endl;
  	return ans1+ans2+mergecount;
  
  
}

int main()
{
	int n;
	cin>>n;
	
	int * arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<solve(arr,n)<<endl;
}	
