#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

int main(void)

{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	stack<pair<int, int>> s; //Ű, ���� �� ��

	ll result = 0;

	for (int i = 0; i < N; i++)
	{
		int h;
		cin >> h;

		//���� ����� Ű�� ������ top�� �ִ� ������� ũ�ٸ�

		while (!s.empty() && s.top().first < h)
		{
			result += s.top().second;
			s.pop();
		}

		if (s.empty())
			s.push({ h, 1 });

		else {
			//���� Ű�� ��� ���� ó��

			if (s.top().first == h) {
				pair<int, int> cur = s.top();
				s.pop();
				result += cur.second;
				//���� �� ���� ū ����� ���� �̷�
				if (!s.empty())
					result++;

				//�����ؼ� ���� Ű�� �����Ƿ�
				cur.second++;
				s.push(cur);
			}

			//�� ���� ����� ���� ���

			else
			{
				s.push({ h, 1 });
				result++;
			}
		}
	}
	cout << result << "\n";

	return 0;

}