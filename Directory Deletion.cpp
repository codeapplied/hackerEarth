// # Problem:

// # - You are given a directory tree of 'N' directories/folders. Each directory is represented by a particular 'id' which ranges from 1 to 'N.
// # - The id of the root directory is 1, then it has some child directories, those directories may contain some other ones and it goes on.
// # - Now you are given a list of directory id's to delete, you need to find the minimum number of directories that need to be deleted so that all the directories in the given list get deleted. 

// # Note:
// # that if you delete a particular directory, all its child directories will also get deleted.

// # Input:
// # - The first line of input contains an integer 'N' that denotes how many folders are there.
// # - The next line contains N space separated integers that where the 'i^th' integer denotes the id of the parent of the directory with id i.
// # - Note that the first integer will be  as  is the id of root folder and it has no parent. Rest of the integers will not be -1 .
// # - The next line contains an integer M that denotes how many directories you need to delete.
// # - The next line contains M space separated integers that denote the ids of the directories you need to delete.

// # Output:
// # Print the minimum number of directories that need to be deleted.

// # (1) <= (N) <= (10^5)
// # (1) <= (M) <= (N)
// # (1) <=(id of parent)<= (N)
// # (1) <=(id to be deleted)<= (N)

// # ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001]={ };
vector<int> del(100001,0);

int tim=0;

void dfs(int i,vector<int> adj[],bool visited[])
{
	stack<int> temp;
	visited[i]=1;
	temp.push(i);
	if(i==del[i])
	{
		cout<<"1";
		return ;
	}
	while(!temp.empty())
	{
		int f=temp.top();
		temp.pop();
		for(int u: adj[f])
		{
			if(visited[u]==0)
			{
				visited[u]=1;
				if(del[u]==u)
				{
					tim++;
				}
				else
					temp.push(u);
			}
		}
	}
	cout<<tim-1<<"\n";
}

int main()
{
	int n,x,y,g,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x==-1)
			x=0;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	cin>>g;
	while(g--)
	{
		cin>>x;
		del[x]=x;
	}
	dfs(1,adj,visited);
}
