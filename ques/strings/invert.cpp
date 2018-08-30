#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    
    int f,s;
    cin>>f>>s;
    
   
    if(isupper(str[f-1]))
    {
        
        str[f-1] = tolower(str[f-1]);
       
    }
    
    else
    {
        str[f-1] = toupper(str[f-1]);
    }
    
    if(isupper(str[s-1]))
    {
        str[s-1] = tolower(str[s-1]);
    }
    
    else
    {
        str[s-1] = toupper(str[s-1]);
    }
    
    cout<<str<<endl;
}
