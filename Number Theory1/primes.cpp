#include<iostream>
using namespace std;

bool checkPrime(int n)
{
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
      return false;
  }
  
  return true;
}

int sieve(int n)
{
	bool * primes = new bool[n+1];
	for(int i=0;i<=n;i++)
	{
		primes[i] = true;
	}
	
	primes[0] = false;
	primes[1] = false;
	
	for(int i=2;i*i<=n;i++)
	{
		if(primes[i])
		{
			if(!checkPrime(i))
			{
				primes[i] = false;
			}
			
			for(int j=i*i;j<=n;j+=i)
			{
				primes[j] = false;
			}
		}
	}
	int count=0;
	for(int i=2;i<=n;i++)
	{
		if(primes[i])count++;
	}
	
	return count;
	
}

int numPrime(int n)//sieve without optimizations
{
  bool * primes = new bool[n+1];
  for(int i=0;i<=n;i++)
  {
    primes[i]=true;
  }
  
  primes[0]=false;
  primes[1]=false;
  
  for(int i=2;i<=n;i++)
  {
    if(primes[i])
    {
      if(!checkPrime(i))
      {
        primes[i]=false;
      }
      
      for(int j=2*i;j<=n && j>=0;j+=i)
      {
        primes[j]=false;
      }
    }
  }
  
  int count=0;
  for(int i=2;i<=n;i++)
  {
    if(primes[i])
      count++;
  }
  
  return count;
}

int main(){
	// Write your code here
  
  	int n;
  	cin>>n;
  
  	cout<<sieve(n)<<endl;
	return 0;
}
