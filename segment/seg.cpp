#include<bits/stdc++.h>

using namespace std;

void update(int * tree, int si, int ei, int ci, int i,int val)
{
	if(si==i && ei==i)
	{
		tree[ci]=val;
		return;
	}
	
	int mid = (si+ei)/2;
	if(mid>=i)
	{
		update(tree,si,mid,2*ci,i,val);
	}
	
	else
	{
		update(tree,mid+1,ei,2*ci+1,i,val);
		
	}
	
	tree[ci]=tree[2*ci]+tree[2*ci+1];
}

void buildtree(int * arr,int * tree,int si,int ei,int ci)
{
	if(si==ei)
	{
		tree[ci] = arr[si];
		return;
	}
	
	int mid = (si+ei)/2;
	buildtree(arr,tree,si,mid,2*ci);
	buildtree(arr,tree,mid+1,ei,2*ci+1);
	
	tree[ci] = tree[2*ci]+tree[2*ci+1];
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int * tree = new int[18];
	memset(tree,0,sizeof(int)*18); 
	
	buildtree(arr,tree,0,8,1);
	for(int i=1;i<18;i++)
	{
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	
	update(tree,0,8,1,2,6);
	for(int i=1;i<18;i++)
	{
		cout<<tree[i]<<" ";
	}
	cout<<endl;
}
