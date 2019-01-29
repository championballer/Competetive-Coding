#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int subarrays(ll * arr, int n)
{
	if(n==0 || n==1)return 0;

	int current = 0;
	current+=(subarrays(arr+1,n-1));

	int arg = 0;
	int odd = 0;
	int even = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)even++;
		else odd++;

		if(even==odd)arg++;
	}

	return current+arg;
}

int main()
{
	int n;
	cin>>n;
	ll * arr = new ll[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<subarrays(arr,n)<<endl;
}