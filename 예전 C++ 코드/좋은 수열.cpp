#include<iostream>
#include<vector>
using namespace std;

int N;

//���� ���� �Ǻ�
bool good(vector<int> v) {
	int Size = v.size();
	bool pos = false;

		for (int i = 1; i <= Size / 2; i++) {
			pos = false;
			for (int j = 0; j < i; j++) {
				if (v[Size - 1 - j] != v[Size - 1 -j- i]) pos = true;
			}
			if (pos == false) return pos;
			
		}
		return pos;
}

void func(vector<int> v) {
	if (v.size() > 1) {
		if (!good(v)) {//���������� �ƴϸ� return
			return;
		}
	}
	if (v.size() == N) {//���� �����̰� ���̰� n�̸� ���
		for (int i = 0; i < N; i++) {
			cout << v[i];
		}
		exit(0);//��°����ÿ� exit.
	}
	vector <int> v1 = v;
	v1.push_back(1);
	func(v1);
	vector <int> v2 = v;
	v2.push_back(2);
	func(v2);
	vector <int> v3 = v;
	v3.push_back(3);
	func(v3);
}




int main() {
	cin >> N;
	vector<int> a;
	func(a);
}