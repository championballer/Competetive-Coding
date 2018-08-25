#include<bits/stdc++.h>

using namespace std;

int charToInt(char a)
{	
	return a-'0';
}

int alphadp(string s)
{
	int * arr = new int[s.size()+1];
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<=s.size();i++)
	{
		arr[i]=arr[i-1];
		int flag = charToInt(s[s.size()-i])*10+charToInt(s[s.size()-i+1]);
		
		if(flag>9 && flag<27)
		{
			arr[i]+=arr[i-2];
		}
	}
	
	return arr[s.size()];
	
}
int helper(string s, int * arr)
{
	if(arr[s.size()]!=-1)
	{
		return arr[s.size()];
	}
	
	if(s.size()==0 || s.size()==1)
	{
		arr[s.size()]=1;
		return arr[s.size()];
	}
	
	int ans = helper(s.substr(1),arr);
	
	int flag = charToInt(s[0])*10+charToInt(s[1]);
	
	if(flag>9 && flag<27)
	{
		ans+=helper(s.substr(2),arr);
	}
	
	arr[s.size()]=ans;
	return ans;

}

int alphaMem(string s)
{
	int * arr = new int[s.size()+1];
	for(int i=0;i<=s.size();i++)
	{
		arr[i]=-1;
	}	
	
	return helper(s,arr);
}

int alpha(string s)
{
	if(s.size()==0 || s.size()==1)
	{
		return 1;
	}
	
	int ans = alpha(s.substr(1));
	int flag = charToInt(s[0])*10+charToInt(s[1]);
	
	if(flag>9 && flag<27)
	{
		ans+=alpha(s.substr(2));
	}
	
	return ans;
}

int main()
{
	string s;
  	cin>>s;
  
  	while(s!="0")
    {
      cout<<alphadp(s)<<endl;
      cin>>s;
    }
}
