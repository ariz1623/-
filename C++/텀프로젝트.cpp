#include<iostream>

using namespace std;

int N, cnt;
int line[100001];
bool visited[100001];
bool done[100001]; // �湮���� ����

void DFS(int node) {

	visited[node] = 1;
	int next = line[node];
	//�湮�����̾����� ���
	if (!visited[next]) DFS(next);
	
	//�湮������ �ִµ� ������尡 �ƴϴ�.->����Ŭ���̷�
	else if (!done[next]) {
		
		
		//������ ������ , for�� �߿�
		for (int i = next; i != node; i = line[i])cnt++;

		cnt++;

	}
	done[node] = 1;
}

void reset(int num) {
	for (int i = 0; i < num; i++) {
		visited[i] = 0;
		line[i] = 0;
		done[i] = 0;
	}
}
int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		reset(N);

		for (int j = 1; j <= N; j++) {
			cin >> line[j];
		}

		//�����̷����Ǽ�
		cnt = 0;

		for (int j = 1; j <= N; j++) {
			if (!visited[j])
				DFS(j);
		}

		//�����̷������� ����Ǽ�
		cout << N - cnt << endl;
	}
}