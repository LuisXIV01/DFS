
#include <bits/stdc++.h>

using namespace std;

bool vis[200005];
vector<int> adjlist[200005];
void dfs(int u){
    vis[u] = true;
    for(int v: adjlist[u]){
        if(!vis[v]){
            dfs(v);
		}
    }
}
int main(){
	//freopen("output.txt","w", stdout);
	int n, count;
	char l;
	string ar;
	cin >> n;
	
	getline(cin, ar);
	cin.ignore();
	for(int k=0; k < n; k++){
		count =0;
		if(k) cout << '\n';
		cin >> l;
		cin.ignore();
		getline(cin, ar);
		while(ar.size() != 0){
			adjlist[ar[0]-65].push_back(ar[1]-65);
			adjlist[ar[1]-65].push_back(ar[0]-65);
			getline(cin, ar);
			//scanf("%s",ar);
		}
		for(int i=65; i <=l; i++){
			if(!vis[i-65]){
				dfs(i-65);
				count++;
			}
		}
		cout << count << "\n";
		for(int j=0;j<=l-64;j++){
			adjlist[j].clear();
			vis[j] = false;
		}
	}
}
