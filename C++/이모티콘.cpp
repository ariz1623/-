
#include<iostream>
#include<algorithm>
using namespace std;

int N;

int arr[2000];

void func(int n, int cnt, int copy) {


	//�ּڰ� ����
	if (arr[n] > cnt || arr[n] == 0)
		arr[n] = cnt;
	else
		return;

	//1����
	if (n > 1 )
		func(n - 1, cnt + 1, copy);


	//�ٿ��ֱ�
	if (n + copy < 2000 && copy > 0 )
		func(n + copy, cnt + 1, copy);


	//��� �����ؼ� �ٿ��ֱ�
	if (n + n < 2000 && n > 0 )
		func(n + n, cnt + 2, n);

}



int main() {
	cin >> N;
	arr[1] = 1;
	func(2, 2, 1);
	cout << arr[N];

}
