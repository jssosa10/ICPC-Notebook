#include <bits/stdc++.h>
using namespace std;
//choose MAXN according to the problem.
const int MAXN = 100005;
vector<int> g[MAXN],gr[MAXN];
bool vis[MAXN];
stack<int> tp;
int n,m;
int scc = 0;
void dfs(int x){
	vis[x]=1;
	for(vector<int>::iterator it = g[x].begin(); it!=g[x].end(); ++it){
		int y = *it;
		if(!vis[y])
			dfs(y);
	}
	tp.push(x);
}
void dfs2(int x){
	vis[x]=1;
	for(vector<int>::iterator it = gr[x].begin(); it!=gr[x].end(); ++it){
		int y = *it;
		if(!vis[y])
			dfs2(y);
	}
}
int main(){
	//read graph.
	//kosaraju	
	memset(vis,0,sizeof(vis));
	for(int i = 0; i<n; i++)
		if(!vis[i])
			dfs(i);
	memset(vis,0,sizeof(vis));
	while(!tp.empty()){
		int x = tp.top();
		tp.pop();
		if(!vis[x]){
			scc++;
			dfs2(x);
			//do extra things like graph condensation.
		}
	}
        return 0;
}


