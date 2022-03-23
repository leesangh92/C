#include <stdio.h>

void salCal(int* tmp, int size);
int* funcA();

int main()
{
	//int salary[5] = { 1500, 3000, 4500, 7000, 2700 }, i;
	int salary[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, i; // unsized �迭(�������� null ���� ����) // �ݵ�� �ʱ�ȭ�� ���־���Ѵ�. 
	int size;

	size = sizeof(salary) / sizeof(salary[0]);

	printf("%d \n", salary[0]);
	//salCal(salary[0]); // ���� �ҷ�����, ���� ���� ȣ��, call by value (������ �Ѱ谡 ����) : ���� �ҷ��´�. 
	//salCal(salary); // ������ ���� ȣ��, call by reference(���μ��� ��ȭ�� ���μ��� ������ ��ģ��)
	salCal(salary, size);



	int* sudang;

	sudang = funcA();
	printf("main() ���� : %d \n", *sudang);



	funcB();



	funcD();

	return 0;
}

funcD()
{
	//char *p1;
	char* p1 = "!!!World Hello";

	p1;
	//p1 = "Hello World!!!"; // ���ڿ� ��� ������
	printf("p1 : %p, %s \n", p1, p1);
}

funcB()
{
	const float PI = 3.14159; // ������ ���ȭ

	int n1 = 100, n2 = 200;

	int* p1 = &n1;
	*p1 = 150;
	printf("\nfuncB() n1 : %d \n", n1);

	const int* p2 = &n2; // �����͸� ���ȭ
	//*p2 = 250; // const ����� p2 �޸� �ּҿ� �ִ� ������ ������ �ٲ� �� ����. 
	printf("\nfuncB() n2 : %d \n", n2);
}

int *funcA()
{
	static int su; // ��������. �׳� int su;�� ��������� su�� ���������� �ٸ� �����Ͱ� �ش� �޸� �ּҿ� ���� *sudang�� ��°��� ���Ѵ�.(���������� ����� ����)
	printf("���� ? ");
	scanf("%d", &su);

	return &su; // return������ �������̸� �޴� ������ �������̴�.
}

//salCal(int tmp[9], int size) // ���ȣ ���� ���ڴ� �������
//salCal(int tmp[], int size)
void salCal(int *tmp, int size)//salCal(int tmp) // ������ ����� ����Ͽ� ���
{
	int i, salTot = 0;

	//printf("salCal() : %d \n", tmp);
	printf("%p, %d \n", tmp, sizeof(tmp));
	/*
	for (i = 0; i < 5; i++)
	{
		printf("%d, ", *(tmp + i));
		salTot += *(tmp + i);
	}
	printf("\n��� : %f \n", (float)salTot/5);
	*/
	for (i = 0; i < size; i++)
	{
		//printf("%d, ", tmp[i]);
		printf("%d, ", *(tmp + i));
		//salTot += tmp[i];
		salTot += *(tmp + i);
	}
	printf("\n��� : %f \n", (float)salTot / size);
	/*
	*tmp += 1000;
	printf("%d \n", *tmp);
	*/
}