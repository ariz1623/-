#include<iostream>
#include<algorithm>
using namespace std;
int arr[10][10];
int num[6] = { 0,5,5,5,5,5 };
int result = 101;

//���� ���ϼ��ִ��� �Ǵ��ϴ� �Լ�.
bool possible(int y, int x, int n) {

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != 1)return false;
		}
	}
	return true;
}

void Fill(int y, int x, int n, int num) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			arr[i][j] = num;
		}
	}
}

void func(int y, int x, int cnt) {
	{//���� Ž���� �������� ����Ž�� ����
	if (x == 10){
		func(y + 1, 0, cnt);
		return;
	}
	//���� Ž���� �������� �ּҰ� ����
	if (y == 10) {
		result = min(result, cnt);
		return;
	}
	//0 �̸� Ȯ���� �ʿ� x
	if (arr[y][x] == 0) {
		func(y, x + 1, cnt);
		return;
	}
	//ũ�Ⱑ 5���� �����Ƿ� 5���� 1����
	for (int i = 5; i > 0; i--) {
		//���� �ʰ� , ���� �ʰ�
		if (x + i > 10 || y + i > 10 || num[i] == 0) continue;// 
		//���̸� ���ϼ������� .
		if (possible(y, x, i)) {
			Fill(y, x, i, 0);//���̰�
			num[i]--;//���� ���
			func(y, x, cnt + 1);//���� ���� ++
			num[i]++;//���� ����
			Fill(y, x, i, 1);//����
		}


	}

}



int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	func(0, 0, 0);
	if (result == 101) cout << -1;
	else cout << result;
}

