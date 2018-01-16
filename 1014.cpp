#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

#define maxk 1010
#define maxn 25
using namespace std;

int n, m, k, q;
int query[maxk];
struct clientnode{
	int id;
	int weight;
	int timespan;
	bool is_wait_inline = false;
}node[maxk];

int main(void){
	
	cin >> n >> m >> k >> q;
	queue<clientnode> wait_inline[maxn];
	queue<clientnode> wait_out;
	for (int i = 0; i < k; ++i){
		scanf("%d", &node[i].weight);
		node[i].id = i;
	}
	for (int i = 0; i < q; ++i){
		scanf("%d", &query[i]);
	}


	for (int i = 0; i < n*m; ++i){
		wait_inline[i%n].push(node[i]);
		node[i].is_wait_inline = true;
	}
	for (int i = n*m; i < k; ++i){
		wait_out.push(node[i]);
	}
	
	clientnode* pnode;
	while (!wait_out.empty())
	}


	return 0;
}