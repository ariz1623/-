#include<iostream>
#include <string>
#include <vector>
#include<math.h>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sum = brown + red;
	int garo, sero;
	//i�� �ּҰ��� 3�̰� �ִ밪�� sqrt(sum)�̴�.( ����� �ִ밪 )
	for (int i = 3; i <= sqrt(sum); i++) {
		//i�� sum�� ����̸�
		if (sum % i == 0) {
			garo = i;
			sero = sum / i;
			if ((garo - 2) * (sero - 2) == red) {  // ����ī�� �� ���̿� ������
				answer.push_back(sero);
				answer.push_back(garo);
			}
		}

	}

	return answer;
}
int main() {
	vector<int>a = solution(3, 3);

	cout << a[0] << a[1];
}