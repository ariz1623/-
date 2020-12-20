#include <iostream>
#include <algorithm>

using namespace std;
int N, M, H, minCnt = 9999999, map[31][11];

// �ڱ� �ڽŰ� ��Ī�Ǵ� ��ٸ����� �Ǵ��ϴ� �Լ�
bool checkLadder() {
	for (int i = 1, pos; i <= N; i++) {
		pos = i;
		for (int j = 1; j <= H; j++) {
			if (map[j][pos] == 1)    pos++;
			else if (map[j][pos - 1] == 1) pos--;
		}
		if (i != pos) return false;
	}
	return true;
}


// ����Լ� : (x, y) ���� ��ٸ��� �߰��Ͽ� ��ٸ� ������ �ּҰ��� ����, cnt�� ���� �߰��� ��ٸ� ����
void func(int cnt, int x, int y) {

	// ���ʿ��� Ž���� Ż���ϴ� ���� (����ġ��, ��Ʈ��ŷ)
	if (cnt >= minCnt) return;

	// ���� ��
	if (checkLadder()) {
		minCnt = cnt;
		return;
	}
	if (cnt == 3) return;


	for (int i = y; i <= H; i++)
		for (int j = x; j < N; j++) {
			if (map[i][j]) {
				j++;
				continue;
			}

			map[i][j] = 1; // ��ٸ� �߰�, �ذ� ��
			func(cnt + 1, 1,i); //���� ��
			map[i][j] = 0;
		}
}
int main() {
	
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	func(0, 1, 1);

	if (minCnt > 3)cout << "-1";
	else cout << minCnt;

}