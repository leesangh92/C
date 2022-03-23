#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

// void funCalc(int (*fp5)(int, int));
void funCalc(FP);
typedef int (*FP)(int ,int); // �Լ� ������ �ڷ��� ���� => �Լ������͸� typedef�� �����ϸ� �Լ������� ������ �ƴ�, �Լ������� �ڷ����� �ȴ�. 

int main()
{
	int ret;

	ret = add(100, 30);
	printf("0. add() : %d \n\n", ret);

	// 1. �Լ������� ������ ����Ͽ� sub �Լ��� ȣ��
	int (*fp1)(int, int);
	fp1 = sub;
	ret = (*fp1)(100, 30);
	printf("1. sub() : %d \n\n", ret);

	// 2. �����ǵ� �Լ������� �ڷ������� �Լ������� ���� ����
	FP fp2; // �Լ������� ���� : �Լ������� �ڷ����� �Լ������� ������
	FP fp3;
	fp2 = add;
	fp3 = sub;
	printf("2. add() : %d \n", (*fp2)(100, 30));
	printf("2. sub() : %d \n\n", (*fp3)(100, 30));

	// 3. �����ǵ� �Լ������� �ڷ������� �Լ������� �迭 ����
	FP fp4[5]; // �Լ������� �迭
	fp4[0] = add;
	fp4[1] = sub;
	printf("3. add() : %d \n", (*fp4[0])(100, 30));
	printf("3. sub() : %d \n\n", (*fp4[1])(100, 30));

	// 4. �Լ��� ȣ���� �� �Լ� �ּҸ� ���μ��� ����
	funCalc(add);
	funCalc(sub);


	return 0;
}
/*
void funCalc(int (*fp5)(int, int)) // 4. ���μ��� �Լ������� ����
{
	printf("4. funCalc() : %d \n", (*fp5)(100, 30));
}
*/

void funCalc(FP fp5) 
{
	printf("4. funCalc() : %d \n", (*fp5)(100, 30));
}