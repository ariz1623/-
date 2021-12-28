#include <iostream>
#include <vector>

using namespace std;


int sudoku[9][9];

bool row[9][10]; //��, 1~9
bool col[9][10]; //��, 1~9
bool square[9][10]; //3*3 �ڽ� idx, 1~9

int change2SquareIdx(int y, int x)

{
	return (y / 3) * 3 + x / 3;
}

void DFS(int cnt)
{
	if (cnt == 81) //Sudoku�� �� 81ĭ
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << sudoku[i][j] << " ";
			cout << endl;
		}
		exit(0); //���� �ϳ��� ���
	}


	int y = cnt / 9;
	int x = cnt % 9;


	if (sudoku[y][x]) //ĭ�� ä����������
		DFS(cnt + 1);
	else //ä�������� �ʾҰ�
	{
		for (int k = 1; k <= 9; k++)
		{
			//sudoku ��Ģ�� �����ϸ� ä��� ����
			if (!col[x][k] && !row[y][k] && !square[change2SquareIdx(y, x)][k])
			{
				sudoku[y][x] = k;
				col[x][k] = true;
				row[y][k] = true;
				square[change2SquareIdx(y, x)][k] = true;
				DFS(cnt + 1);
				sudoku[y][x] = 0;
				col[x][k] = false;
				row[y][k] = false;
				square[change2SquareIdx(y, x)][k] = false;
			}
		}
	}
}



int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			if (sudoku[i][j])
			{
				col[j][sudoku[i][j]] = true;
				row[i][sudoku[i][j]] = true;
				square[change2SquareIdx(i, j)][sudoku[i][j]] = true;
			}
		}
	}

	DFS(0); //sudoku�� 81ĭ

	return 0;
}