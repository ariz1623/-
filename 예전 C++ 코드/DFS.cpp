#include<iostream>
#include<algorithm>


using namespace std;

int visited[100][100];
int map[100][100];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


//�׷����� ������Ʈ �������ϱ�
int dfsAll() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}

		}
	}
	return cnt;
}
void dfs(int x, int y) {
	//�̹̹湮�Ͽ��ٸ� return
	if (visited[x][y]) return;

	//�湮 üũ
	visited[x][y] = 1;

	//��,��,��,�� 4���� Ž��
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < 100 && next_y >= 0 && next_y < 100) {\
			//Ž�������ϴٸ� ���ȣ��.
			if (map[next_x][next_y] && !visited[next_x][next_y])
				dfs(next_x, next_y);
		}
	}
}
int main() {
	int result = dfsAll();
	cout << result;
}