#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


bool compare_length(string str, string str2) {
	//���̰� ª�� ������ �켱
	if (str.length() < str2.length()) {
		return 1;
	}
	else if (str.length() > str2.length()) return 0;
	//���̰� ������� 
	else return  str < str2;/// ���� ������ ����
}

vector<string> v;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), compare_length);

	for (int i = 0; i < n; i++) {
		if (i < n - 1&&v[i] == v[i + 1] )continue;
		cout << v[i] << "\n";
	}
}


