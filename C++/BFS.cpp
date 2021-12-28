#include<iostream>
#include<queue>


using namespace std;

int map[100][100];
int visited[100][100];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int cnt = 0;

void BFS() {
	queue <pair<int, int>> q;
	//���� ���� q�� push
	q.push(make_pair(0, 0));

	//������ �湮 üũ
	visited[0][0] = 1;

	//ť�� �� ���°� �ɶ����� �ݺ�
	while (!q.empty()) {

		int size = q.size();

		//cnt�� bfs�� ���̸� ��Ÿ��.

		cnt++;

		for (int i = 0; i < size; i++) {
			//q�� front�κ��� �߽�����
			pair<int, int> x = q.front();
			q.pop();
			int a = x.first;
			int b = x.second;
			//4������ Ž���Ѵ�. 
			for (int j = 0; j < 4; j++) {
				int next_x = a + dx[i];
				int next_y = b + dy[i];

				//�迭�ʰ� ���� Ȯ��
				if (next_x >= 0 && next_x < 100 && next_y >= 0 && next_y < 100) {
					//�̵��� ���ְ� �湮 ���� �ʾ������ q�� �ִ´�.
					if (map[next_x][next_y] && !visited[next_x][next_y]) {
						q.push(make_pair(next_x, next_y));
						visited[next_x][next_y] = 1;
					}
				}
			}
		}
	}

}


int main() {
	cout << cnt;
}