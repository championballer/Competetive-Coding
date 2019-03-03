#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> sample1;

	sample1.push_back(1);
	sample1.push_back(2);

	vector<int> sample2;
	sample2 = sample1;

	for(int i=0;i<sample1.size();i++)
	{
		cout<<sample1[i]<<" ";
	}

	for(int i=0;i<sample2.size();i++)
	{
		cout<<sample2[i]<<" ";
	}

	sample1[1] = 3;
	
	for(int i=0;i<sample2.size();i++)
	{
		cout<<sample2[i]<<" ";
	}	

	
}