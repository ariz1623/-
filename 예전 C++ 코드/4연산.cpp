# include<iostream>

int s, t;
char ans[32];
int minLen = 987654321;
char arr[32];
bool fin = false;

void func(int s, int idx) {
	if (s > t)
		return;
	if (s == t) {
		fin = true;
		if (idx < minLen) {
			for (int i = 0; i < idx; i++) {
				ans[i] = arr[i];
			}
			minLen = idx;
		}
		return;
	}

	//1�϶��� ���ѷ���,31623 ���ʰ��ϸ� ���� �ʰ�
	if (s != 1 && s < 31623) {
		arr[idx] = '*';
		func(s * s, idx + 1);
	}
	//5���� �ʰ��ϸ� ���� �ʰ�
	if (s <= 500000000) {
		arr[idx] = '+';
		func(s + s, idx + 1);
	}
}
int main() {

	scanf("%d %d", &s, &t);
	if (s == t) {
		printf("0\n");
		return 0;
	}
	
	if (t == 0) {
		printf("-\n");
	}
	else if (t == 1) {
		printf("/\n");
	}

	else {
		func(s, 0);
		arr[0] = '/';
		func(1, 1);
		if (fin == false) {
			printf("-1\n");
			return 0;
		}

		for (int i = 0; i < minLen; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}