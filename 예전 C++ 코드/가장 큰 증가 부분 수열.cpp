#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1001];
	int dp[1001];
	for (int i = 0; i < N; i++)cin >> arr[i];

	for (int i = 0; i < N; i++)dp[i] = 0;

	for (int i = 0; i < N; i++) {
		int num = 0;
		for (int j = i; j >= 0; j--) {
			
			if (arr[i] > arr[j]) {//�ڱ⺸�� ���� �ε������� ���� ���� �߰� �ߴ� .
				num =max(num, arr[i] + dp[j]); //���� �ִ밪�� ã�°� .
			}
			
			
		}
		dp[i] = num;
		if (dp[i] == 0)dp[i] = arr[i];// �ڱ⺸�� �Ʒ� �ε������� �ڱ� ���� �������ڰ� ������ �׳� �ڱ⸦ DP �迭�� ����.
	}
	int result = 0;

	for (int i = 0; i < N; i++) {
		result = max(result, dp[i]);
	}
	cout << result;

}