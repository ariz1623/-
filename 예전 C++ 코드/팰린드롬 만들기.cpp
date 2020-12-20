#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	string s;

	int arr[26],cnt=0,idx=-1;

	
	cin >> s;
	
	//���ĺ� ���� �迭 �ʱ�ȭ
	for (int i = 0; i < 26; i++)arr[i] = 0;

	//���ĺ� ��������
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - 'A']++;
	}
	
	for (int i = 0; i < 26; i++) {
		//���ĺ� ������ Ȧ��
		if (arr[i] % 2 == 1) {
			cnt++;
			idx = i;
		}

	}

	//������ Ȧ������ ���ĺ��� ���� 2���̻��̸� �Ӹ������ ���� ������
	if (cnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	string answer = "";
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i] / 2; j++) {
			answer.push_back('A' + i);
		}
	}

	if(idx!=-1)
	answer.push_back('A' + idx);

	for (int i = 25; i >= 0; i--) {

		for (int j = 0; j < arr[i] / 2; j++) {
			answer.push_back('A' + i);
		}
	}

	cout << answer;

}