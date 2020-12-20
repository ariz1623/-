#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll > func(ll  N)
{
	ll  two = 0, five = 0;
	// N! ���� 2�� �ǰ��� 
	for (ll i = 2; i <= N; i *= 2)
		two += N / i;

	//N! ���� 5�� ���� 
	for (ll i = 5; i <= N; i *= 5)
		five += N / i;
	return { two, five };

}



int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll  N, M;
	cin >> N >> M;
	vector<pair<ll, ll >> v(3);

	v[0] = func(N); //N!
	v[1] = func(M); //M!
	v[2] = func(N - M); //(N-M)!
	ll f = v[0].first - v[1].first - v[2].first;
	ll t = v[0].second - v[1].second - v[2].second;

	//�ǵڰ� 0�̵Ƿ��� 5�� 2���� �ϳ��� �ʿ��ϹǷ� ���� �������� ���.
	cout << min(f, t);
	

}