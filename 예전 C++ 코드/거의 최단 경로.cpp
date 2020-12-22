#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m, x, y, z, s, e;
int a[502][502];
int dp[502];

//���ͽ�Ʈ��
//���⼭�� ������ �迭�� �����Ͽ��µ� ���� �ִ��� ������ Ŀ���� vector�α����ؾ���.
void dijkstra() {

	//�迭 �ʱ�ȭ
	memset(dp, -1, sizeof(dp));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (pq.size()) {

		int curr = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (dp[curr] != -1)continue;
		dp[curr] = dist;
		for (int i = 0; i < n; i++) {
			if (a[curr][i] == -1)continue;
			if (dp[i] != -1)continue;
			pq.push({ -dist - a[curr][i],i });
		}
	}
}


//�ִ� ��� ���� 
void del() {
	queue<int> qu;
	qu.push(e);

	while (qu.size()) {
		int cx = qu.front();
		qu.pop();

		for (int i = 0; i < n; i++) {
			if (dp[cx] == dp[i] + a[i][cx] && a[i][cx] != -1) {
				a[i][cx] = -1;
				qu.push(i);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	while (n != 0 && m != 0) {
		scanf("%d%d", &s, &e);
		memset(a, -1, sizeof(a));
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = z;
		}

		dijkstra();
		del();
		dijkstra();

		printf("%d\n", dp[e]);
		scanf("%d%d", &n, &m);
	}

	return 0;
}


