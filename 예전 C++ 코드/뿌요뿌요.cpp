#include<iostream>


using namespace std;
char map[13][7];
int visited[13][7];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void down() { // ������ �����ִ� �Լ�
	for (int i = 11; i > 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.') {
				if (map[i - 1][j] != '.') {
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = '.';
				}
				else if (i-2>=0&&map[i - 2][j] != '.') {
					map[i][j] = map[i - 2][j];
					map[i - 2][j] = '.';
				}
				else if (i - 3 >= 0 && map[i - 3][j] != '.') {
					map[i][j] = map[i - 3][j];
					map[i - 3][j] = '.';
				}
				else if (i - 4 >= 0 && map[i - 4][j] != '.') {
					map[i][j] = map[i - 4][j];
					map[i - 4][j] = '.';
				}
			}
		}
	}
}
bool pos = false;
int pos_cnt = 0;
void dfs_size(int y, int x, char C) {
	
	if (visited[y][x]) {
		return;
	}
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < 6 && next_y >= 0 && next_y < 12) {
			if (!visited[next_y][next_x] && map[next_y][next_x] == C) {
				dfs_size(next_y, next_x, C);
				pos_cnt++;
			}
		}
	}
}

void dfs(int y, int x, char C) {
	if (visited[y][x]) {
		return;
	}
	visited[y][x] = 1;
	map[y][x] = '.';
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= 0 && next_x < 6 && next_y >= 0 && next_y < 12) {
			if (!visited[next_y][next_x] && map[next_y][next_x] == C) {
				map[next_y][next_x] = '.';
				dfs(next_y, next_x, C);
			}
		}
	}
}
void reset() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int ans = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	bool next = false;
	while (1) {
		
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {

				if (map[i][j] != '.') {
					//�ѿ䰡 ��� �پ��ִ���
					dfs_size(i, j, map[i][j]);					
					reset();
					//�ѿ䰡 ������������ ��Ʈ����.
					if (pos_cnt>=3) {
						dfs(i, j, map[i][j]);
						next = true;
					}
					pos_cnt = 0;
				}
	
			}

		}
		//�ѿ� ������ ������ ! 
		down();		

		//�ѿ䰡 ������������ break
		if (!next)break;
		//�湮 �ʱ�ȭ
		reset();
		//next �ʱ�ȭ
		next = false;
		//�޺� ++
		ans++;
	}

	cout << ans;
}