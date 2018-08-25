#include<bits/stdc++.h>

using namespace std;

int moves[8][2] = {{2,1},{1,2},{2,-1},{-2,1},{-2,-1},{1,-2},{-1,-2},{-1,2}};

void fact(int * dp, int n)
{
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = dp[i-1]*i;
    }
}

int pro(vector<int> sizes)
{
    int prod = 1;
    int mx = 0;
    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i]>mx)mx = sizes[i];
    }
    int * dp = new int[mx+1];
    fact(dp,mx);
    
    for(int i=0;i<sizes.size();i++)
    {
        prod = prod*dp[sizes[i]];
    }
    return prod;
}

void dfs(int ** board,int n,int m,int cx,int cy,int & size)
{	
	if(cx>=n || cy>=m || cx<0 || cy<0)return;
	if(board[cx][cy]==0 || board[cx][cy]==2)return;
	board[cx][cy] = 2;
	size++;
	for(int i=0;i<8;i++)
	{
		int nx = cx+moves[i][0];
		int ny = cy+moves[i][1];
		dfs(board,n,m,nx,ny,size);
		
	}
	
	//return 1+size;
}

//1 9 9 12 2 4 2 7 3 5 4 3 4 7 5 5 6 2 7 7 8 3 8 5 9 6 9 9
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m,p;
		cin>>n>>m>>p;
		
		int** board = new int*[n];
		for(int i=0;i<n;i++)
		{
			board[i] = new int[m];
			for(int j=0;j<m;j++)
			{
				board[i][j] = 0;
			}
		}
		
		vector<pair<int,int> > points;
		for(int i=0;i<p;i++)
		{
			int f,s;
			cin>>f>>s;
			board[f-1][s-1]=1;
			points.push_back(make_pair(f-1,s-1));
		}
	
		vector<int> sizes;
		for(int i =0;i<p;i++)
		{
			
			pair<int,int> point;
			point = points[i];
			int cx = point.first;
			int cy = point.second;
			if(board[cx][cy]==1)
			{
				int size =0;
				dfs(board,n,m,cx,cy,size);
				sizes.push_back(size);
			}
		}
		cout<<pro(sizes)<<endl;
	}
}
