#include<bits/stdc++.h>

using namespace std;



int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		
		int n;
		cin>>n;
		int place;
		cin>>place;
		int * arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,greater<int>());
		
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}		
		cout<<endl;
		int q = place;
		for(int i=place;i<n;i++)
		{
			if(arr[i] == arr[place-1])q++;
			else break;
		}
		cout<<q<<endl;
	}
}
