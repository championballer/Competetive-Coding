#include<bits/stdc++.h>

using namespace std;

void print(int** arr,int n)
{
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;

}

void helper(int ** arr, int n, int cn, int cx,int cy)
{
 	
  if(cn==0)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<arr[i][j]<<" ";
      }
    }
    cout<<endl;
  	return;
  }
  
  if(cx>n-1)return;
  if(cy>n-1)return;
  int flag = 0;
  
  int i=cx,j=cy;
  while(i>=0 && !flag)
  {
    if(arr[i][j]!=0)
    {
      flag=1;
      break;
    }
    i--;
  }
  
  i=cx,j=cy;
  while(j>=0 && !flag)
  {
    if(arr[i][j]!=0)
    {
      flag=1;
      break;
    }
    j--;
  }
  
  i=cx,j=cy;
  while(i>=0 && j>=0 && !flag)
  {
    if(arr[i][j]!=0)
    {
      flag=1;
      break;
    }
    
    i--;
    j--;
  }
  
  i=cx,j=cy;
  while(i>=0 && j<n && !flag)
  {
    if(arr[i][j]!=0)
    {
      flag=1;
      break;
    }
    i--;
    j++;
  }
  
  if(flag)
  {
    helper(arr,n,cn,cx,cy+1);
  }
  
  else
  {
    arr[cx][cy]=1;
    helper(arr,n,cn-1,cx+1,0);
  }
  
  arr[cx][cy]=0;
  helper(arr,n,cn,cx,cy+1);

  
  return;  
}


void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	
  	int ** arr = new int*[n];
  	for(int i=0;i<n;i++)
    {
      arr[i] = new int[n];
      for(int j=0;j<n;j++)
      {
        arr[i][j]=0;
      }
    }
  
  	helper(arr,n,n,0,0);

}

int main()
{
	int n;
	cin>>n;
	
	placeNQueens(n);
}

