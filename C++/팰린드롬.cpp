#include<iostream>

using namespace std;

int dp[2002][2002];
int N, M, arr[2002];
void func() {

	//���̰� 1�� ������ ������ �Ӹ�����̴�.
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}

	//���̰� 2�� ������ �յڰ� ������ �Ӹ�����̴�.
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i + 1])dp[i][i + 1] = 1;
		else dp[i][i + 1] = 0;
	}

	//���̰� 3�̻�
	//���̰� 3�ΰͺ��� N�ΰ� ������ ���ϴ°�

	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			//�յڰ� ���� ,�� �� ���̿��ִ� ������ �Ӹ������ ���
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];

	cin >> M;

	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++) {
			dp[i][j] = 0;
		}
	}

	func();
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
}