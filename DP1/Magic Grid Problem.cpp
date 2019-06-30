#include <bits/stdc++.h>
using namespace std;

int magic(int ** hp, int m,int n)
{
  
  
  int ** aux = new int*[m];
  for(int i=0;i<m;i++)
  {
    aux[i] = new int[n];
  }
  
  aux[m-1][n-1]=1;
  aux[m-1][n-2]=1;
  aux[m-2][n-1]=1;
  
  for(int i=m-3;i>=0;i--)
  {
    aux[i][n-1] = aux[i+1][n-1]-hp[i+1][n-1];
    if(aux[i][n-1]<1)aux[i][n-1]=1;
  }
  
  for(int j=n-3;j>=0;j--)
  {
    aux[m-1][j] = aux[m-1][j+1]-hp[m-1][j+1];
    if(aux[m-1][j]<1)aux[m-1][j]=1;
  }
  
  for(int i=m-2;i>=0;i--)
  {
    for(int j=n-2;j>=0;j--)
    {
      aux[i][j] = min(aux[i+1][j]-hp[i+1][j],aux[i][j+1]-hp[i][j+1]);
      if(aux[i][j]<1)aux[i][j]=1;
    }
  }
  
  return aux[0][0];
}

int main()
{
  	int t;
  	cin>>t;
  
  	while(t!=0)
    {
      int m,n;
      cin>>m>>n;
      
      int ** hp = new int*[m];
      for(int i=0;i<m;i++)
      {
        hp[i] = new int[n];
        for(int j=0;j<n;j++)
        {
          cin>>hp[i][j];
        }
      }
      
      cout<<magic(hp,m,n)<<endl;
      
      t--;
    }
    return 0;
}
