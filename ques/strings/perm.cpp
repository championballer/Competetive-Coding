#include<bits/stdc++.h>

using namespace std;

vector<string> perm(string str)
{
    if(str=="")
    {
        vector<string> result;
        result.push_back("");
        return result;
    }
    
    vector<string> result;
    for(int i=0;i<str.length();i++)
    {
        string sub = "";
        for(int j=0;j<str.length();j++)
        {
            if(i==j)continue;
            else sub+=str[j];
        }
        
        vector<string> sans = perm(sub);
        for(int j=0;j<sans.size();j++)
        {
            result.push_back(str[i]+sans[j]);
        }
    }

    return result;
}

int main()
{
    string str;
    cin>>str;
    
    vector<string> result = perm(str);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
