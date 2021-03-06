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

void updateTree(int * arr, int * tree, int l,int r, int i, int index, int value)
{

	if(l==r)
	{
		arr[index] = value;
		tree[i] = value;
		return;
	}
	int mid = (l+r)/2;
	if(index>mid)
	{
		updateTree(arr,tree,mid+1,r,2*i+1,index,value);
	}

	else
	{
		updateTree(arr,tree,l,mid,2*i,index,value);
	}

	tree[i] = tree[2*i]+tree[2*i+1];
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int * tree = new int[18];

	buildTree(arr,tree,0,8,1);

	for(int i=1;i<18;i++)cout<<tree[i]<<" ";
	cout<<endl;

	updateTree(arr,tree,0,8,1,4,10);

	for(int i=1;i<18;i++)cout<<tree[i]<<" ";
	cout<<endl;

}