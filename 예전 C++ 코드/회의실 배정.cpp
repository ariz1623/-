#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<pair<long long,long long>> p;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++ ) {
		int a, b;
		cin >> a>>b;
		p.push_back(make_pair(b,a));
	}
	sort(p.begin(), p.end());//����ð� ���� �������� ����
	int result=1;// �ϳ��� ������ �ϴϱ� 1���ͽ���
	int num = p[0].first;
	for (int i = 1; i < n; i++) {
		if (p[i].second >= num) {//ȸ�� ������ ������ ���� ���������� ȸ�Ǹ� ����.
			num = p[i].first;
			result++;
		}

	}
	cout << result;
	

}