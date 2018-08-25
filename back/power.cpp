#include<iostream>
using namespace std;

int power(int n,int x)
{
  if(n==0)return 1;
  if(n==1)return x;
  
  int sans = power(n/2,x);
  if(n%2==0)
  {
    return sans*sans;
  }
  
  else
  {
    return sans*sans*x;
  }
}

int main() {
	// Write your code here
	int n,x;
  	cin>>n>>x;
  	cout<<power(n,x)<<endl;
}

