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
    string str;
    cin>>str;
    
    string max = str;
    for(int i=0;i<str.length();i++)
    {
        rotate(str);
        if(str>max)max = str;
    }
    cout<<max<<endl;
}
