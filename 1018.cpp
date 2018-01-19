//ensure min_from,if not unique,then ensure min_to
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define maxn 510
#define INF 1000000000

using namespace std;
int g[maxn][maxn];
int dis[maxn];
int weight[maxn];

int cmax;//max bikes in a certain station
int n;//station numbers;
int sp;//no.sp station is in problem
int m;//number of roads int graph

int minNeed=INF;
int minBack=INF;
bool vis[maxn];

vector<int> pre[maxn];//��¼ǰ�� ���·���ľ���·�������ڿ��ܴ��ڶ���·���������������ʽ

vector<int> temppath, path;//vector֮�����ֱ��ͨ���ȺŸ�ֵ����

void dfs(int v){//temppath[0]=sp
	temppath.push_back(v);
	if (v == 0){
		//temppath �����ʱ����һ�������Ĵ�sp��0��·��
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--){//��tempp��ĩβ��ʼ
			int id = temppath[i];
			if (weight[id] > 0){
				back += weight[i];
			}
			else{
				if (back > (0 - weight[id])){//���ǰ������ʣ��Ŀ����ֲ�
					back += weight[id];
				}
				else{//�������ֲ���ȫ�������ʼ��need����
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed){//minNeedֻ����һ����ֻ���γ�һ��temppath��ʱ������ж�
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack){
			minBack = back;
			path = temppath;
		}
		return;
	}
	for (int i = 0; i < pre[v].size(); ++i){
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}

int main(void){
	//input && init
	fill(dis, dis + maxn, INF);
	fill(g[0], g[0] + maxn*maxn, INF);

	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for (int i = 1; i <=n; ++i){
		scanf("%d", &weight[i]);
		weight[i] -= cmax / 2;
	}
	int sa, sb, tempdistant;// temp station
	for (int i = 0; i <m; ++i){
		scanf("%d%d%d", &sa, &sb, &tempdistant);
		g[sa][sb] = g[sb][sa] = tempdistant;
	}

	//simple source shortest path ---Dijkstra
	dis[0] = 0;
	for (int i = 0; i <= n; ++i){
		int u = -1, min = INF;
		for (int j = 0; j <= n; ++j){
			if (vis[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		if (u == -1)
			break;
		vis[u] = true;
		for (int v = 0; v <= n; ++v){
			if (vis[v] == false && g[u][v] != INF){
				if (dis[v]>dis[u] + g[u][v]){
					dis[v] = dis[u] + g[u][v];
					//˵����̵ĸ���pre���������dis�����¹���pre[i]�е����ݲ��������ˣ�Ӧ��clear��
					pre[v].clear();
					pre[v].push_back(u);
				}
				if (dis[v] == dis[u] + g[u][v])
					pre[v].push_back(u);
			}
		}
	}

	//dfs---to solve minNeed && minBack
	dfs(sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; --i){
		printf("->%d", path[i]);
	}
	printf(" %d", minBack);

	return 0;
}