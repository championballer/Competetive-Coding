#include<bits/stdc++.h>

using namespace std;

int kadane(int * arr, int n)
{
	int current = 0;
	int best = 0;
	for(int i=0;i<n;i++)
	{
		current+=arr[i];
		if(current>best)best = current;
		if(current<0)current = 0;
	}
	return best;
}

int main()
{
	int arr [] = {-2, -3, 4, -1, -2, 1, 5, -3};

	cout<<kadane(arr,8)<<endl;
}