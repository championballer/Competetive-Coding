#include<bits/stdc++.h>

using namespace std;

void rotate(string & str)
{
    char current = str[0];
    str = str.substr(1);
    str+=current;
}

int main()
{	
	string a = "aux";
	string c = "bux";
	string b = "";
	
	rotate(a);
	cout<<a<<endl;
}
