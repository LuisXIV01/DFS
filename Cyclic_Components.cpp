#include <bits/stdc++.h>

using namespace std;

bool vis[200005], uno;
vector<int> adjlist[200005];
void dfs(int u){
    vis[u] = true;
    if(adjlist[u].empty())
		uno = false;
    for(int v: adjlist[u]){
        if(!vis[v]){
			if(adjlist[v].size() != 2)
				uno = false;
            dfs(v);
		}
    }
}
int main(){
	int n, m, u, v, cycle=0;
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	for(int i=1; i <=n; i++){
		uno = true;
		if(!vis[i]){
			dfs(i);
			if(uno)
				cycle++;
		}
	}
	cout << cycle << '\n';
}
