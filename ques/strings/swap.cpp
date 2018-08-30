#include<bits/stdc++.h>

using namespace std;

void swap(string & str)
{
	string aux = "";
	for(int i=1;i<str.length();i+=2)
	{
		aux = str[i]+aux;
	}

	string aux2 = "";
	for(int i=0;i<str.length();i+=2)
	{
		aux2+=str[i];
	}
	
	str=aux2+aux;
}

int main()
{
	int k;
	cin>>k;
	
	string str;
	cin>>str;
	
	for(int i=0;i<k;i++)
	{
		swap(str);
	}
	
	cout<<str<<endl;

	
	
}
