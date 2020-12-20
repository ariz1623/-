#include<iostream>
#include<math.h>

using namespace std;
typedef long long ll;

pair<int, int> prince, flower;

int func(ll y, ll x, ll r) {
	int num = 0;
	
	ll dist = (prince.first - x) * (prince.first - x) + (prince.second - y) * (prince.second - y);

	//���ڰ� �༺���� ����������
	if (dist <= r*r) {
		num++;
	}

	
	ll dist2 = (flower.first - x) * (flower.first - x) + (flower.second - y) * (flower.second - y);

	//���� ���� �༺���� ����������
	if (dist2 <= r*r) {
		num++;
	}

	//���� �ϳ��� ���������� ������ �ϴ� �༺�� �ϳ� �߰�
	if (num == 1) return 1;

	//�������� �༺�踦 ������ �ʾƵ��ȴ�.
	else return 0;
}

int main() {


	int a, b, c, d, M, T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> a >> b >> c >> d;
		prince = make_pair(a, b);
		flower = make_pair(c, d);

		cin >> M;
		int result = 0;
		for (int i = 0; i < M; i++) {
			ll x, y, r;
			cin >> x >> y >> r;
			result += func(y, x, r);
		}
		cout << result << "\n";
	}
}