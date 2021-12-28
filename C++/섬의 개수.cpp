#include<iostream>
using namespace std;



int map[51][51];
int visited[51][51];
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
int dx[8] = { 0,0,1,-1,1,-1,- 1,1 };
int w, h;

void dfs(int y, int x) {
	if (visited[y][x]) return;

	visited[y][x] = 1;

	//8���� Ž��
	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		//�迭 ���
		if (next_x >= 0 && next_y >= 0 && next_y < h && next_x < w) {
			if (!visited[next_y][next_x] && map[next_y][next_x]) {
				dfs(next_y, next_x);
			}
		}
	}
}

// �ʱ�ȭ �Լ�
void reset(int y, int x) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}

}
int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)break;

		//�����Է�
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
		reset(h, w);
	}
}