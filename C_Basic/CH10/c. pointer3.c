#include <stdio.h>
#include <string.h>

int main()
{
	int num[5] = { 100, 200, 300, 400, 500 };
	int i, *ptr; // *ptr : ������ ���� -> ������ ����ʹ� �ٸ��� ������ �����ϴ�. 

	ptr = num;
	
	printf("\n");
	for (i = 0; i < 5; i++)
		//printf("%p, %d, %d \n", &num[i], num[i], *(num+ i));
		//printf("%d, %d, %d \n", num + i, num[i], *(num + i)); // ÷�ڰ� ���� �迭 ������ �� �迭�� �����ּҸ� ��Ÿ����. 
		//printf("%p, %d, %d \n", &num[i], num[i], *(ptr + i));
		//printf("%p, %d, %d \n", &num[i], num[i], *ptr + i);
		printf("%p, %d, %d, %d \n", num + i, num[i], *(ptr + i), *(num + i), ptr[i]);
		printf("\n");



	char str[20] = "kingdom", * p2;

	p2 = str;
	printf("%c, %c, %c, %c \n", str[0], *(str + 0), *(str + 1), *p2); // ������
	printf("&p, %s, %s \n", str, str, p2);                            // �ּ�

	/*
	p2�� ����Ͽ� k, i, n, g, d, o, m �� ���
	*/
	
	for (i = 0; i < strlen(p2); i++)
	{
		printf("%d. *(p2+i) : %c \n", i, *(p2+i)); // *(p2+i) , *p2+i �� ����  // �ּ� �ϳ��� ����
		//printf("%d. *p2+i : %c \n", i, *p2+i); // ���ĺ� ���� �ϳ��� ����
	}
	
	
	while(*p2) // \n(null)���� ������ 0���� ������ �Ǿ� ������ ������. while(p2)�̸� ���ѷ���. while(*str)
	{
		printf("%c, ", *p2);
		//printf("%c, ", *str);
		p2++;
		//str++; // ÷�ڰ� ���� �迭 ������ �� �迭�� �Ҵ�� �޸��� �����ּҸ� ���� ������ ����̴�. ������ �Ұ����ϴ�!!!
	}

	return 0;
}