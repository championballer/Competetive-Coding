#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    
    vector<string> words;
    
    string current = "";
    for(int i=0;i<str.length();i++)
    {
        char toprocess = str[i];
        current = "";
        while(toprocess!=' ' && i!=str.length())
        {
            current+=toprocess;
            i++;
            toprocess = str[i];
        }
        words.push_back(current);
    }
    
    string aux = "";
    for(int i=0;i<words.size()-1;i++)
    {
    	string current = words[i];
    	aux+=current[0];
    	aux+=". ";
    }
    
    aux+=words[words.size()-1];
    cout<<aux<<endl;
    
    
    
}
