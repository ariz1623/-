#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	int arr[101];
	vector<int> mult;
	cin >> N >> K;
	int result = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	mult.push_back(arr[0]);

	for (int i = 1; i < K; i++) {
		
		if (mult.size() == N) {// �÷��װ� ��� �����
			bool pos = false;
			for (int j = 0; j < N; j++) {
				if (arr[i] == mult[j]) {//�÷��װ� �̹� �����ִ�
					pos = true;
				}
			}
			if (pos == true) continue;
			else {//�÷��װ� ���������ʴ� .
				result++;//�÷��׸� 1ȸ ���� ������ result++;
				vector<pair<int, int>> p;

				for (int j = 0; j < N; j++) {
					int idx = 100; //idx �ִ밪
					for (int k = i; k < K; k++) {
						if (mult[j] == arr[k]) {//�����ִ� �÷����� ���� ����� ���� ã�ƾߵ�
							idx = k;
							break;
						}
					}
					p.push_back(make_pair(idx, mult[j]));//����� ���̾����� idx ��100�״��
				}
				::sort(p.begin(), p.end());
			
				mult[N-1] = arr[i];// ��������ǰ �ű�
				for (int j = 0; j < N-1; j++) {
					mult[j] = p[j].second;  //���� ���߿� ����� ��ǰ����� �ȕ����Ǵϱ� ���� ���д�
				}
			}
		}
		else {//�÷��װ� ��� ������� �ƴϴ�
			bool pass = false;
			for (int j = 0; j < mult.size(); j++) {
				if (arr[i] == mult[j]) {//�̹� ���������� pass
					pass = true;
					break;
				}
			}
			if (!pass)mult.push_back(arr[i]);//�������������� �Ŵ´�.
		}
	}
	cout << result;

}