#include<iostream>
using namespace std;

int charToInt(char a)
{
  return a-'0';
}

int helper(string b,int a)
{
  if(b.size()==1)
  {
    return charToInt(b[0])%a;
  }
  
  int smallAns = helper(b.substr(0,b.size()-1),a);
  return ((((smallAns%a)*(10%a))%a)+(charToInt(b[b.size()-1])%a))%a;
}

int gcd(int a,int b)
{
  if(b==0)return a;
  
  return gcd(b,a%b);
}
int advGcd(int a, string b)
{
  int sub = helper(b,a);
  
  return gcd(a,sub);
}

int main(){
	// Write your code here
  
  	int t;
  	cin>>t;
  
  	while(t)
    {
      int a;
      string b;
      
      cin>>a;
      cin>>b;
      cout<<advGcd(a,b)<<endl;
      
      t--;
    }
	return 0;
}
