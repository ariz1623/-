#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

ll N, M;
int arr[1000000];

int main() {
	int max_num = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		max_num = max(max_num, arr[i]);
	}

	//hi�� max_num ���� ����.
	int lo = 0, hi = max_num;
	// �̺� Ž�� ����
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		// �� ������ ���� mid�� ���ܱ� ���� ������ �� ����� ���� �� ���ϱ�
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if (arr[i] > mid) sum += arr[i] - mid;
		// mid�� M �̻��� ���̸� ������ �� ����

		
		if (sum >= M) lo = mid;
		// mid�� M �̻��� ���̸� ������ �� ����
		else hi = mid;
	}
	cout << lo;
	

}