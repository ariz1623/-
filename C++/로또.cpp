#include<iostream>
#include<vector>

using namespace std;

int check[50]; //��뿩��
int num[50];
int N;

void func(int idx, vector<int> v) {

	//����� , ���
	if (v.size() >= 6) {
		for (int i = 0; i < 6; i++)cout << v[i] << " ";
		cout << "\n";
		return;
	}



	for (int i = idx; i < N; i++) {
		//�̹� ����ߴٸ� SKIP
		if (check[i])continue;

		check[idx] = 1;
		v.push_back(num[i]);
		func(i + 1, v);

		//��Ʈ��ŷ
		v.pop_back();
		check[idx] = 0;
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	while (1) {
		cin >> N;

		if (N == 0)break;
		//����S �Է�
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}

		func(0, {});
		cout << "\n";

		//reset
		for (int i = 0; i < N; i++) {
			check[i] = 0;
			num[i] = 0;
		}
	}
}
