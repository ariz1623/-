#include<iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> a;  // L
vector<int> b;   //R
int Size;
int dp[2002][2002];
int func(int L, int R) {
	if (L == Size || R == Size) return dp[L][R]; //���� ī�带 �ٹ����� �� ~ 
	if (dp[L][R] != 0) return dp[L][R]; 
	
		dp[L][R] = max(func(L + 1, R), func(L + 1, R + 1)); //���ʸ� �����ų� �Ѵٹ����ų�
		if (a[L] > b[R]) {
			dp[L][R] = max(dp[L][R], func(L, R + 1) + b[R]);//�����ʸ� ������ �����׵�.
		}
		return dp[L][R];

}


int solution(vector<int> left, vector<int> right) {
	a = left;	
	b = right;
	Size = a.size();
	int answer = func(0, 0);
	return answer;
}