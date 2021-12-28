#include <iostream>
#include <queue>

using namespace std;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int R, C;
pair<int, int> S, D;
char map[55][55];
queue<pair<int, int>> mul;
int visited[55][55];



int BFS() {

	queue<pair<int, int>> go;
	go.push(S);
	visited[S.first][S.second] = 1;
	int cnt = 0;
	while (!go.empty()) {
		cnt++;

		int Size = mul.size();
		//������ ä���
		for (int i = 0; i < Size; i++) {

			int y = mul.front().first;

			int x = mul.front().second;

			mul.pop();



			for (int j = 0; j < 4; j++) {

				int nextY = y + dy[j];
				int nextX = x + dx[j];

				if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C) {

					//��ĭ�� ����ä���.
					if (map[nextY][nextX] == '.') {
						map[nextY][nextX] = '*';
						mul.push(make_pair(nextY, nextX));
					}
				}
			}
		}


		int goSize = go.size();

		for (int i = 0; i < goSize; i++) {
			int y = go.front().first;
			int x = go.front().second;
			go.pop();

			//������ ���� ��
			if (y == D.first && x == D.second)
				return cnt;



			//�δ����� ������ ����

			for (int j = 0; j < 4; j++) {

				int nextY = y + dy[j];

				int nextX = x + dx[j];



				if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C)

					//���� ���ΰ��� �湮 x ������ �湮�Ѱ� �湮 x
					if (map[nextY][nextX] != '*' && map[nextY][nextX] != 'X' && visited[nextY][nextX] == 0) {
						visited[nextY][nextX] = 1;
						go.push(make_pair(nextY, nextX));
					}

			}

		}

	}

	return -1;

}



int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int result;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {



		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S')
				S = make_pair(i, j);
			else if (map[i][j] == '*')
				mul.push(make_pair(i, j));
			else if (map[i][j] == 'D')
				D = make_pair(i, j);
		}
	}


	result = BFS();
	if (result == -1)
		cout << "KAKTUS" << endl;
	else
		cout << result - 1 << endl;
	return 0;

}

