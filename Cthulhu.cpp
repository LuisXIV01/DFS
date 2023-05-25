#include <bits/stdc++.h>

using namespace std;

bool vis[200005];
vector<int> adjlist[200005];
int cnt =0;
void dfs(int u){
    vis[u] = true;
    cnt++;
    for(int v: adjlist[u]){
        if(!vis[v]){
            dfs(v);
		}
    }
}
int main(){
	//freopen("output.txt","w", stdout);
	int n, m, a, b;
	cin >> n >> m;
	for(int i=0; i < m; i++){
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	if(n != m) cout << "NO\n";
	else{
		dfs(1);
		if(cnt != n) cout << "NO\n";
		else cout << "FHTAGN!\n";
	}
	
}
