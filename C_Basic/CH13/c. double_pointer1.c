#include <stdio.h>

int main()
{
	int num;
	int * ip; // ���� ������ : ������ ���� �ּҸ� ����
	int ** mip; // ���� ������ : ������ ������ ���� �ּҸ� ����

	printf("%d, %d, %d \n", sizeof(num), sizeof(ip), sizeof(mip));

	ip = &num;
	mip = &ip;

	**mip = 500;

	printf("%d, %d, %d \n\n", num, *ip, **mip);




	char* ptr[] = { "kingdom", "Multi Campus", "Hello World!!!", "one �ϳ�", "two ��" , "seoul ����� ������ ���ﵿ", "busan �λ�� �ؿ�뱸 �ؿ�뵿", NULL };

	funcA(ptr);

	return 0;
}

// ptr�� ����� ���ڿ� ���
funcA(char **tmp)
{
	int len = 0;
	char* ptr;

	printf("funcA() : %p, %d \n\n", tmp, sizeof(tmp));

	while (*tmp) 
	{
		ptr = *tmp;
		while (*ptr)
		{
			len++;
			ptr++;
		}

		printf("%u : %u, %s, Length : %d \n", tmp, *tmp, *tmp, len);
		len = 0;

		tmp++;
	}
	/*
	while (1)
		if (*tmp != 0)
			printf("%s \n", *tmp);

	printf("%u : %u, %s, %s \n", tmp, *tmp, *tmp, **tmp);
	*/
}