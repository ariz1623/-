#include<iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void func(int n, int y, int x) {
	if (n == 2) {
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {


				if (i == r && j == c) {
					cout << result;
					return;
				}
				result++;
			}
		}
		return;
	}
	else {
		func(n / 2, y, x);// �������
		func(n / 2, y, x + n / 2); //�������
		func(n / 2, y + n / 2, x);//�����ϴ�
		func(n / 2, y + n / 2, x + n / 2);//���� �ϴ�
		return;
	}
}
int main() {
	cin >> N >> r >> c;

	func(pow(2, N), 0, 0);

}