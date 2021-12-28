#include<iostream>
#include<algorithm>
using namespace std;
int coin[101];
int dp[10001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	//���� �Է�
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	//�������� ����
	sort(coin, coin + n);
	
	//dp �ʱ�ȭ
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i] = 0;
	}

	for (int i = 1; i <= k; i++) {
		//ù��° ���� �̿�
		if (i % coin[0] == 0)dp[i] = 1;
	}
	for (int j = 1; j < n; j++) {
		//������ ���� �̿� 
		for (int i = coin[j]; i <= k; i++) {
			dp[i] = dp[i - coin[j]] + dp[i];
		}
	}
	cout << dp[k];
}