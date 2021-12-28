#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int INF = 987654321;



int main(void){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, H;

	cin >> N >> H;

	vector<int> bottom(N / 2), top(N / 2);

	for (int i = 0; i < N / 2; i++) {
		cin >> bottom[i] >> top[i];
	}


	//���� ���� ����( lower_bound,upper_bound����ҷ��� ���ĵǾ��־����)
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int result = INF;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {

		//�ش� ���̿� ��ġ�� ����
		int brk = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

		//�ش� ���̿� ��ġ�� ������
		brk += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (result == brk)cnt++;

		//�ּ� �ı� �� ����
		else if (result > brk) {
			result = brk;
			cnt = 1;
		}		
	}
	
	cout << result << " " << cnt << "\n";
}



