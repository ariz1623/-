#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recommend[101];

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	//���� , ����
	vector<pair<int, int>> v(N);


	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		recommend[num]++;

		bool change = true;
		for (int j = 0; j < N; j++) {

			//����Ʋ�� ����ִ� ���

			if (v[j].second == 0) {
				v[j].second = num;
				v[j].first = i;
				change = false;
				break;
			}

			//�̹� �ĺ����� ������ ��ϵ� �ִ� ���

			else if (v[j].second == num) {
				change = false;
				break;
			}

		}

		//����Ʋ�� ��������ʰ� ����Ʋ�� �ĺ����� ������ �������

		if (change) {

			int idx = 0;

			for (int j = 1; j < N; j++) {

				//���� ��õ ���� ���� �������� �������� ���
				if (recommend[v[j].second] == recommend[v[idx].second]) {

					//���� ��ϵ� 
					if (v[j].first < v[idx].first) idx = j;

				}

				//��õ���� ���� ������
				else if (recommend[v[j].second] < recommend[v[idx].second]) {
					idx = j;
				}
			}

			recommend[v[idx].second] = 0; //�ٲ������� ��õ�� �ʱ�ȭ

			v[idx].first = i;
			v[idx].second = num;

		}
	}

	vector<int> picture;

	for (int i = 0; i < N; i++) {
		picture.push_back(v[i].second);
	}

	sort(picture.begin(), picture.end());
	for (int i = 0; i < N; i++)cout << picture[i] << " ";
}