#include<iostream>
#include<algorithm>
using namespace std;

int arr[300001];



bool compare(int a, int b) {
	return a > b;
}

int main() {
	
	int N;

	int score = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	//���� ���� ����
	sort(arr, arr + N, compare);
	
	score = arr[0] + 1;
	int result = 1;

	for (int i = 1; i < N; i++) {
		//1���� ���ɼ��� �ִٸ� result++
		if (arr[i] + N >= score) result++;

		//���� ������ ��� ����
		score = max(score, arr[i] + i + 1);
	}
	cout << result;
}