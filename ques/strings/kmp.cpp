#include<bits/stdc++.h>

using namespace std;

void pre(string pattern, int * lps)
{
	lps[0] = 0;
	int len = 0;
	int i = 1;
	
	while(i<pattern.length())
	{
		if(pattern[i]==pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
			continue;
		}
		
		else if(len==0)
		{
			lps[i]=0;
			i++;
			continue;
		}
		
		else
		{
			len = lps[len-1];
		}
	
	}
}

int main()
{
	string pattern,text;
	cin>>pattern>>text;
	
	int * lps = new int[pattern.size()];
	pre(pattern,lps);


	int matched = 0;
	int i=0,j=0;
	while(i<text.length())
	{
		if(pattern[j]==text[i])
		{
			i++;
			j++;
			if(j==pattern.length())
			{
				matched++;
				j--;
			}
		}
		
		else if(j==0)
		{
			i++;
		}
		
		else
		{
			j = lps[j-1];
		}
	}
	
	cout<<matched<<endl;	
}
