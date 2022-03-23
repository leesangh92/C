#include <stdio.h>

void scoreCalc(int(*tmp)[7], int row, int col);
void heading();

int main()
{
	int score[5][7] = {
		{78, 57, 96, 74},
		{35, 98, 67, 95},
		{70, 98, 77, 65},
		{73, 60, 61, 73},
		{83, 50, 91, 65}
	};

	int row, col, i, j;

	row = sizeof(score) / sizeof(score[0]);
	col= sizeof(score[0]) / sizeof(score[0][0]);

	scoreCalc(score, row, col);

	heading();
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			printf("%3d  ", score[i][j]);
		printf("\n");
	}

	return 0;
}

void heading()
{
	printf("===================================================\n");
	printf("���� ���� ���� ���� ���� ��� ���� \n");
	printf("===================================================\n");
}

// score �迭�� ��, ���, ������ ���
//scoreCalc(int (*tmp)[4]) // �迭 ������ ����
//scoreCalc(int(*tmp)[5][4])
//scoreCalc(int(*tmp)[][4])
void scoreCalc(int(*tmp)[7], int row, int col)
{
	int i, j;

	printf("scoreCalc() : %d, %p \n\n", sizeof(tmp), tmp);
	/*
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			//printf("%3d, ", tmp[i][j]);
			printf("%3d ", *(*(tmp+i)+j));
		printf("\n");
	}
	*/
	// ����, ���
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			tmp[i][4] += tmp[i][j];
			//printf("%3d, ", tmp[i][j]);
			//printf("%3d ", *(*(tmp + i) + j));
			*(*(tmp + i) + 5) = *(*(tmp + i) + 4) / (col - 3);
	}
	// ����
	for (i = 0; i < row; i++)
	{
		tmp[i][6] = 1;
		for (j = 0; j < row; j++)
		{
			if (tmp[i][5] < tmp[j][5])
				tmp[i][6]++;
		}
	}
}