#include<iostream>
#include<algorithm>
using namespace std;



int N;
int arr[21][21];
int new_map[21][21];
int map[21][21];
int result = 0;
void left() {//�������� �̴� �Լ�

	for (int i = 0; i < N; i++) {
		int num = 0;
		int idx = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0)continue;
			else {
				if (num == 0)num = map[i][j];
				else {
					if (num == map[i][j]) {
						new_map[i][idx++] = num * 2;
						num = 0;
					}
					else {
						new_map[i][idx++] = num;
						num = map[i][j];
					}
				}
			}
		}
		if (num != 0) new_map[i][idx] = num;
	}
	for (int i = 0; i < N; i++) {// new_map �� ans�� �־��ְ� new map�� 0���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
			new_map[i][j] = 0;
		}
	}

}
void right() {//���������� �̴� �Լ�

	for (int i = 0; i < N; i++) {
		int num = 0;
		int idx = N - 1;
		for (int j = N - 1; j >= 0; j--) {
			if (map[i][j] == 0)continue;
			else {
				if (num == 0)num = map[i][j];
				else {
					if (num == map[i][j]) {
						new_map[i][idx--] = num * 2;
						num = 0;
					}
					else {
						new_map[i][idx--] = num;
						num = map[i][j];
					}
				}
			}
		}
		if (num != 0) new_map[i][idx] = num;
	}
	for (int i = 0; i < N; i++) {// new_map �� ans�� �־��ְ� new map�� 0���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
			new_map[i][j] = 0;
		}
	}
}
void up() {//���� �ø��� �Լ�

	for (int j = 0; j < N; j++) {
		int num = 0;
		int idx = 0;
		for (int i = 0; i < N; i++) {
			if (map[i][j] == 0)continue;
			else {
				if (num == 0)num = map[i][j];
				else {
					if (num == map[i][j]) {
						new_map[idx++][j] = num * 2;
						num = 0;
					}
					else {
						new_map[idx++][j] = num;
						num = map[i][j];
					}
				}
			}
		}
		if (num != 0) new_map[idx++][j] = num;
	}
	for (int i = 0; i < N; i++) {// new_map �� ans�� �־��ְ� new map�� 0���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
			new_map[i][j] = 0;
		}
	}
}
void down() {//�Ʒ��� ������ �Լ�

	for (int j = 0; j < N; j++) {
		int num = 0;
		int idx = N - 1;
		for (int i = N - 1; i >= 0; i--) {
			if (map[i][j] == 0)continue;
			else {
				if (num == 0)num = map[i][j];
				else {
					if (num == map[i][j]) {
						new_map[idx--][j] = num * 2;
						num = 0;
					}
					else {
						new_map[idx--][j] = num;
						num = map[i][j];
					}
				}
			}
		}
		if (num != 0) new_map[idx--][j] = num;
	}
	for (int i = 0; i < N; i++) {// new_map �� ans�� �־��ְ� new map�� 0���� �ʱ�ȭ
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
			new_map[i][j] = 0;
		}
	}
}
int check() {// �迭���� �ִ밪
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num = max(num, map[i][j]);
		}
	}
	return num;
}

void func(int cnt) {//��ͷ� ����
	if (cnt == 6) return;//5��������
	result = max(result, check());

	int copyBoard[21][21];

	//�� ������� �����س���

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copyBoard[i][j] = map[i][j];

	right();
	func(cnt + 1);
	//���� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = copyBoard[i][j];
	left();
	func(cnt + 1);
	//���� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = copyBoard[i][j];
	up();
	func(cnt + 1);
	//���� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = copyBoard[i][j];
	down();
	func(cnt + 1);
	//���� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = copyBoard[i][j];

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	func(0);
	cout << result;
}