#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define maxn 1010
using namespace std;

int conn[maxn][maxn];
bool vis[maxn];
int n, m, k;

void dfs(int node){
	for (int i = 1; i <= n; ++i){
		if (vis[i] == false && conn[node][i] == 1){
			vis[i] = true;
			dfs(i);
		}
	}
}

int main(void){

	cin >> n >> m >> k;
	int temp1, temp2, node;
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &temp1, &temp2);
		conn[temp1][temp2] = 1;
		conn[temp2][temp1] = 1;
	}

	for (int i = 0; i < k; ++i){
		fill(vis, vis + maxn, false);
		int ans = 0;
		scanf("%d", &node);
		vis[node] = true;
		for (int j = 1; j <= n; ++j){
			if (vis[j] == false){
				dfs(j);
				ans++;
			}
		}
		printf("%d\n", ans-1);
	}

	return 0;
}