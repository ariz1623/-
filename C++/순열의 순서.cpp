#include<iostream>
#include<vector>
using namespace std;


int N, num;
vector<int> v,ans;

int check[21];
long long factorial[21],cnt=0,k;

int main() {


	cin >> N;
	factorial[0] = 1;
	//���丮���� �̸����
	for (int i = 1; i < 21; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	cin >> num;
	//���� 1��
	if (num == 1) {
		cin >> k;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				//�̹� ����� ���ڴ� continue
				if (check[j]) continue;
				//���丮�� ���� k ���� ������ k�� factorial ��ŭ ����
				if (factorial[N - 1-i] < k) {
					k = k - factorial[N - 1-i];
				}
				else {
					//���丮�� ���� k���� ũ�ų� ������ ��º��Ϳ� push.
					ans.push_back(j);
					check[j] = 1;
					break;
				}
			}
		}
		
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}

	}
	//���� 2��
	else {
		for(int i = 0 ;i<N;i++){
			int k;
			cin >> k;
			v.push_back(k);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (!check[j]) {
					cnt += factorial[N - i - 1];
				}			
			}
			check[v[i]] = 1;
		}
		cout << cnt + 1;


	}



}