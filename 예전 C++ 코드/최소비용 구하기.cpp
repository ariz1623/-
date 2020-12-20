#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

typedef pair<int, int> P;
int INF = 987654321;
int N, M;
vector<P> v[1005];
int check[1005];
void dijkstra(int start) {
	check[start] = 0; //���� ��ġ�� �Ÿ� 0
	priority_queue<P> pq;
	pq.push(P(start, 0)); // ������ �־��ְ� 

	while (!pq.empty()) {
		int curr = pq.top().first;
		int dis = -pq.top().second;

		pq.pop();

		//�ִܰŸ��� �ƴѰ�� continue
		if (check[curr] < dis)continue;

		for (int i = 0; i < v[curr].size(); i++) {

			//���õ� ����� �������
			int next = v[curr][i].first;
			
			//���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextdis = dis + v[curr][i].second;			
			if (nextdis < check[next]) {
				check[next] = nextdis;
				pq.push(P(next, -nextdis));
			}
		}
	}
	return;

}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> N>>M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(P(b, c));
	}
	int s, e;
	cin >> s >> e;
	for (int i = 1; i <= N; i++) check[i] = INF;
	dijkstra(s);

	cout << check[e];

}