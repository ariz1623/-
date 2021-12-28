#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int map[105][105];

void reset() {
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			map[i][j] = 0;
		}
	}
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t, num;

	cin >> t;
	for (int T = 0; T < t; T++) {
		//�迭 �ʱ�ȭ
		reset();

		//������ ����
		cin >> num;
		int a, b;
		pair<int, int> start, end;
		cin >> a >> b;

		//���� ����
		start = make_pair(a, b);
		vector<pair<int, int>> v;

		//������ ��ǥ
		for (int j = 0; j < num; j++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		//���� ����
		cin >> a >> b;
		end = make_pair(a, b);


		//�� �������� �ٸ��������� �����ִ� �� Ȯ��.
		for (int i = 0; i < num + 2; i++) {
			for (int j = 0; j < num + 2; j++) {
				if (i == j)continue;
				if (map[i][j])continue;
				
				//start
				if (i == 0) {
					//��������
					if (j == num + 1) {
						if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
							map[i][j] = 1;
							map[j][i] = 1;
						}
					}
					//������
					else {
						if (abs(start.first - v[j - 1].first) + abs(start.second - v[j - 1].second) <= 1000) {
							map[i][j] = 1;
							map[j][i] = 1;
						}

					}
				}

				//end
				else if (i == num + 1) {
					//�������
					if (j == 0) {
						if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000) {
							map[i][j] = 1;
							map[j][i] = 1;
						}
					}
					//������
					else {
						if (abs(end.first - v[j - 1].first) + abs(end.second - v[j - 1].second) <= 1000) {
							map[i][j] = 1;
							map[j][i] = 1;
						}
					}
				}
				//������
				else {
					//��������̰ų� ���������̸� 
					if (j == 0 || j == num + 1)continue;
					else {
						//�ٸ� ������
						if (abs(v[i-1].first - v[j-1].first) + abs(v[i-1].second - v[j-1].second) <= 1000) {
							map[i][j] = 1;
							map[j][i] = 1;
						}
					}

				}


			}
		}


		//�÷��̵� �ͼ� �˰���
		for (int k = 0; k < num + 2; k++) {
			for (int i = 0; i < num + 2; i++) {
				for (int j = 0; j < num + 2; j++) {
					if (map[i][j])continue;

					map[i][j] = max(map[i][j], map[i][k] + map[k][j]);
					if (map[i][j] == 2) {
						map[i][j] = 1;
						map[j][i] = 1;
					}
					else map[i][j] = 0;
				}
			}
		}


	//map[��������][�������� ==1 �̸� happy �ƴϸ� sad
		if (map[0][num + 1])cout << "happy" << "\n";
		else cout << "sad" << "\n";
	}
}
