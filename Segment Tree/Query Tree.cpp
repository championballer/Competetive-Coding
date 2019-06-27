#include<bits/stdc++.h>

using namespace std;

void buildTree(int * arr, int * tree, int l, int r, int i)
{
	if(l==r)
	{
		tree[i] = arr[l];
		return;
	}

	int mid = (l+r)/2;
	buildTree(arr,tree,l,mid,2*i);
	buildTree(arr,tree,mid+1,r,2*i+1);

	tree[i] = tree[2*i]+tree[2*i+1];
}

void updateTree(int * arr, int * tree, int l, int r, int i, int index, int val)
{
	
	if(l==r)
	{
		arr[index] = val;
		tree[i] = val;
		return;
	}

	int mid = (l+r)/2;

	if(index>mid)
	{
		updateTree(arr,tree,mid+1,r,2*i+1,index,val);
	}

	else
	{
		updateTree(arr,tree,l,mid,2*i,index,val);
	}

	tree[i] = tree[2*i]+tree[2*i+1];
}

int queryTree(int * tree, int s, int e, int i, int l, int r)
{
	if(s>r || e<l)return 0;
	if(s>=l && e<=r)return tree[i];

	int mid = (s+e)/2;
	int ans1 = queryTree(tree,s,mid,2*i,l,r);
	int ans2 = queryTree(tree,mid+1,e,2*i+1,l,r);
	return ans1+ans2;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int * tree = new int[10];

	buildTree(arr,tree,0,4,1);
	for(int i=1;i<10;i++)cout<<tree[i]<<" ";
	cout<<endl;
	updateTree(arr,tree,0,4,1,2,10);
	for(int i=1;i<10;i++)cout<<tree[i]<<" ";
	cout<<endl;
	cout<<queryTree(tree,0,4,1,2,4)<<endl;
}