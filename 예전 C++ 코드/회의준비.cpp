#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N, M, arr[101][101], chk[101][101];
int check[101];


//������Ʈ ���ϱ�
void bfs(int n, int num) {

	queue<int> q;
	q.push(n);
	check[n] = num;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (chk[x][i] && !check[i]) {
				q.push(i);
				check[i] = num;
			}
		}

	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> N >> M;
	//�迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 987654321;
			chk[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//������Ʈ�� ���ϱ����� �迭�� �ΰ����� ����� ��ȿ����  �� 
		arr[a][b] = 1;
		arr[b][a] = 1;
		chk[a][b] = 1;
		chk[b][a] = 1;
	}
	int cnt = 0;

	//������Ʈ�� ���ؼ� ����
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			cnt++;
			bfs(i, cnt);
		}
	}


	//�÷��̵� �ͼ�

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int max_ans[101];
	for (int i = 0; i < 101; i++)max_ans[i] = 0;

	//�� �ο����� �ɸ��� �ǻ����޽ð� ���ϱ�.
	for (int k = 1; k <= cnt; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				if (check[i] == k) {
					if (check[j] == k)
						max_ans[i] = max(max_ans[i], arr[i][j]);
				}
			}
		}
	}


	cout << cnt<<"\n";
	vector<int> ans;

	//�� ������Ʈ(����ȸ) �� ��ǥ ���ϱ�.
	for (int i = 1; i <= cnt; i++) {
		pair<int, int> result =make_pair(0, 987654321);
		for (int j = 1; j <= N; j++) {
			if (check[j] == i) {
				if (result.second > max_ans[j]) {
					result = make_pair(j, max_ans[j]);
				}
			}
		}
		ans.push_back(result.first);
	}

	//��ǥ �������� ����
	sort(ans.begin(),ans.end());

	//��ǥ ���
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

}