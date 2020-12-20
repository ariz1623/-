#include<iostream>
#include<algorithm>

using namespace std;


char map[21][21];

bool check[26] = { false };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int R, C, cnt = 0;
void dfs(int y, int x, int count) {

	cnt = max(count, cnt);
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R)
		{
			if (!check[map[next_y][next_x] - 'A'])// ���ĺ��� ��� ���Ѱ���..
			{
				check[map[next_y][next_x] - 'A'] = true;
				dfs(next_y, next_x, count + 1);
				check[map[next_y][next_x] - 'A'] = false; // ������ �ִ밪�� ã�ƾߵǴ� false �� �ʱ�ȭ.
			}
		}

	}

}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	check[map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << cnt;
}
