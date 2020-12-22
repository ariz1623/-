#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;

int start, destination;
vector<pair<int, int>> V[100001];
int visited[100001];

bool BFS(int cost) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int  curr = q.front();
		q.pop();

		//������ ���� �� ���ִٸ� return true 
		if (curr == destination) return true;

		for (int i = 0; i < V[curr].size(); i++) {
			int next = V[curr][i].first;
			int next_cost = V[curr][i].second;


			//�߷� ������ cost �϶� �ٸ��� �ǳ� ���ִ� �� �� Ž��
			if (!visited[next] && cost <= next_cost) {
				visited[next] = true;
				q.push(next);
			}
		}

	}
	//���������� ���� ���ϸ� return false;
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int result = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		//����� �׷��� ����
		V[a].push_back(make_pair(b, c));
		V[b].push_back(make_pair(a, c));

		result = max(result, c);

	}

	cin >> start >> destination;



	//���� Ž��

	int low = 0, high = result;

	while (low <= high) {
		//�迭 �ʱ�ȭ
		for (int i = 0; i <= N; i++)visited[i] = 0;
		int mid = (low + high) / 2;

		if (BFS(mid))
			low = mid + 1;
		else
			high = mid - 1;

	}
	cout << high;
}