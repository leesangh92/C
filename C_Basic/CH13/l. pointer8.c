#include <stdio.h>

int main()
{
	int num[3] = { 100, 200, 300 }, i;
	int *p1[3]; // ������ �迭
	//char* p2[5] = { "kingdom", "Multi Campus", "Hello World!!!", "one �ϳ�", "two ��" };
	char* p2[] = { "kingdom", "Multi Campus", "Hello World!!!", "one �ϳ�", "two ��" , "seoul ����� ������ ���ﵿ", "busan �λ�� �ؿ�뱸 �ؿ�뵿", NULL };
	// unsigned �����͹迭�� �ݵ�� �ʱ�ȭ�� �Ǿ���Ѵ�.

	//printf("sizeof p1 : %d \n", sizeof(p1));
	printf("sizeof p2 : %d \n", sizeof(p2));

	for (i = 0; p2[i]; i++)
		printf("%p, %s \n", p2[i], p2[i]);

	/*
	// p1 �ּ� ����
	for (i = 0; i < 3; i++)
		p1[i] = num + i;

	// p1�� ����Ͽ� 100, 200, 300�� ���
	for (i = 0; i < 3; i++)
		printf("%d, ", *p1[i]);
	printf("\n");
	*/

	return 0;
}