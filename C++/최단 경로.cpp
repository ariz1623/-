#include<iostream>
#include<vector>
#include<queue>

#include<algorithm>

const int INF = 987654321;
using namespace std;
typedef pair<int, int> P;

int V, E, K;
vector<P> v[20005]; // (�̾��� ������ȣ,������ �Ÿ�)
int min_cost[20005];

void dijstra(int start) {
	min_cost[start] = 0;//���� ��ġ�� �Ÿ� 0
	priority_queue<P> pq;
	pq.push(P(start, 0));

	while (!pq.empty()) {
		int curr = pq.top().first;
		//ª�� ���� ���� ������ ����ȭ
		int dis = -pq.top().second;
		pq.pop();

		// �ִܰŸ��� �ƴѰ�� continue
		if (min_cost[curr] < dis)continue;

		for (int i = 0; i < v[curr].size(); i++) {

			//���õ�  ����� �������
			int next = v[curr][i].first;

			//���õ� ��带 ���� ���� ���ļ� ���� ���
			int nextdis = dis + v[curr][i].second;

			//������ �ּҺ�� ���� ������ ��ü
			if (nextdis < min_cost[next]) {
				min_cost[next] = nextdis;
				pq.push(P(next, -nextdis));
			}

		}

	}
	return;

}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(P(b, c));
	}
	for (int i = 1; i <= V; i++)min_cost[i] = INF;

	dijstra(K);

	for (int i = 1; i <= V; i++) {
		if (min_cost[i] == INF)
			cout << "INF" << "\n";
		else
			cout << min_cost[i] << endl;

	}




}
