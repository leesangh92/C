/*
#include <stdio.h>

int main()
{
	char ch, * cp;
	int num, * ip;
	float f_num, * fp;
	double d_num, * dp;

	printf(" ������ ũ�� : %3d, %3d, %3d, %3d \n", sizeof(ch), sizeof(num), sizeof(f_num), sizeof(d_num));
	printf(" ������ ������ ũ�� : %3d, %3d, %3d, %3d \n", sizeof(cp), sizeof(ip), sizeof(fp), sizeof(dp));

	d_num = 17.5;
	cp = &d_num; // �ڷ����� �ٸ��� -> ���� �ҷ��� �� ����

	printf("\n cp�� ������ �� : %lf \n\n", *cp);

	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	char ch, * cp;
	int num, * ip;
	float f_num, * fp;
	double d_num, * dp;

	ch = 'A'; num = 100; f_num = 5.6; d_num = 17.5;
	cp = &ch, ip = &num, fp = &f_num, dp = &d_num;

	printf("�������� ���� �ּ� : %p, %p, %p, %p \n", &ch, &num, &f_num, &d_num);
	printf("�������� �� :       %5c,   %5d, %10.2f, %10.2lf \n\n", ch, num, f_num, d_num);

	printf("������ ������ ����� �ּ� : %p, %p, %p, %p \n", cp, ip, fp, dp);
	printf("�������� �� :               %5c,  %5d, %10.2f, %10.2lf \n", *cp, *ip, *fp, *dp);


	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	char ch, * cp;
	int num, * ip;
	float f_num, * fp;
	double d_num, * dp;

	ch = 'A'; num = 100; f_num = 5.6; d_num = 17.5;
	cp = &ch, ip = &num, fp = &f_num, dp = &d_num;

	printf("������ ������ ���� \n");
	printf("�������� �� :             %5c,    %5d,%10.2f, %10.2lf \n", ch, num, f_num, d_num);
	printf("������ ������ ����� �ּ� : %p, %p, %p, %p \n\n", cp, ip, fp, dp);

	ch++; num++; f_num++; d_num++;
	cp++; ip++; fp++; dp++;

	printf("+1 �� ������ ������ ���� \n");
	printf("�������� �� :               %5c,  %5d, %10.2f, %10.2lf \n", ch, num, f_num, d_num);
	printf("������ ������ ����� �ּ� : %p, %p, %p, %p \n\n", cp, ip, fp, dp);

	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	int num, tmp = 0, *ptr;

	ptr = &num;
	num = 100;

	printf("num : %d, tmp : %d, ptr : %p \n\n", num, tmp, ptr);
	tmp = (*ptr)++;

	printf("num : %d, tmp : %d, ptr : %p \n\n", num, tmp, ptr);
	tmp = *ptr++;

	printf("num : %d, tmp : %d, ptr : %p \n\n", num, tmp, ptr);

	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	int i, count[6] = { 100, 200, 300, 400, 500, 600 };
	int *ptr;

	ptr = count;

	printf("�迭�� ���� �ּ� : %p, %p, %p \n\n", count, &count[0], ptr);

	printf("÷�ڸ� �̿��� ��� : ");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", count[i]);
	}
	printf("\n\n");

	printf("�迭������ �̿��� �����Ϳ��� : ");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", *(count+i));
	}
	printf("\n\n");

	printf("\t\t\t\t");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", *count + i);
	}
	printf("\n\n");

	printf("\t\t\t\t");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", *count);
	}
	printf("\n\n");

	printf("�����ͺ����� �̿��� �����Ϳ��� : ");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", *(ptr + i)); // ptr = count
	}
	printf("\n\n");

	printf("\t\t\t\t");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", *ptr + i);
	}
	printf("\n");

	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20] = "Hello World!!!";
	char* ptr;

	ptr = str;
	
	while (*ptr)
		printf("%c", *ptr++);
	printf("\n\n");
	

	int i;

	for(i = 0; i < strlen(str); i++)
		printf("%c", str[i]);
	printf("\n\n");

	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20] = "Multi Campus.";
	char* msg = "Advanced C."; // *msg ��� �޸� �ּҸ� �Ҵ��ϰ�, "Advanced C." ���ڿ� ��� ���� �ּҸ� �����Ѵ�

	printf("str : %s, msg : %s \n", str, msg);

	strcpy(str, msg); // msg �ּ��� ���ڿ��� str �迭�� �����Ѵ�.
	printf("str : %s, msg : %s \n", str, msg);

	printf("input string ? :");
	gets(str);
	
	//strcpy(msg, str); // str �迭�� ���ڿ��� msg�� ����� �����ּ� �޸𸮿� ���� => msg�� ����Ű�� �޸𸮴� �б����� �޸� 
	//printf("str : %s, msg : %s \n", str, msg); // ��Ÿ�� ����
	
	return 0;
}
*/
/*
#include <stdio.h>

void swap1(int x, int y);

int main()
{
	int x = 100, y = 200;
	printf("main() x : %d, y : %d \n\n", x, y);

	swap1(x, y);
	printf("swap1() main() x : %d, y : %d \n\n", x, y);

	return 0;
}

void swap1(int x, int y);
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}
*/
/*
#include <stdio.h>

void swap2(int *x, int *y);

int main()
{
	int x = 100, y = 200;
	printf("main() x : %d, y : %d \n\n", x, y);

	swap1(&x, &y);
	printf("swap2() main() x : %d, y : %d \n\n", x, y);

	return 0;
}

void swap2(int *x, int *y);
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
*/
/*
#include <stdio.h>

void func1(int* ptr);

int main()
{
	int i, count[5] = { 100, 200, 300, 400, 500 };

	printf("count �迭�� �����ּ� : %p, �迭�� ũ�� : %d \n\n", count, sizeof(count));

	func1(count);
	printf("count �迭�� �� : ");
	for (i = 0; i < 5; i++)
		printf("%d ", count[i]);
	printf("\n\n");

	return 0;
}

void func1(int* ptr)
{
	int i;
	printf("func1() �����ͺ����� ������ �����ּ� : %p, �����ͺ����� ũ�� : %d \n\n", ptr, sizeof(ptr));

	for (i = 0; i < 5; i++)
		*(ptr + i) = *(ptr + i) + 50;
}
*/
/*
#include <stdio.h>

int* mySalary(void);

int main()
{
	int* sal;

	sal = mySalary();

	printf("���� : ȫ�浿 \n");
	printf("�⺻�� : %d \n", *sal);
	printf("����(�⺻���� 15%%) : %.0f \n", (*sal) * 0.15);
	printf("�Ǽ��ɾ�(�⺻�� + ����) : %.0f \n", *sal + ((*sal) * 0.15));

	return 0;
}
int* mySalary(void)
{
	static int salary = 100;

	return &salary;
}
*/
/*
#include <stdio.h>

int main()
{
	int num = 100;
	const int* ptr = &num; // const ���ȭ�� ������

	printf("*ptr : %d \n", *ptr);
	// *ptr = 200; 
}
*/

/*
Ű����κ��� ���ڿ��� �Է¹޾� �̸� �ݴ�� (����������) ����ϴ� ���α׷��� �����͸� �̿��Ͽ� �ۼ�.
���� ���ڿ��� ũ�⸦ ���Ͽ� �Բ� ���.(strlen() �Լ� ���X)
*/
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20], *ptr;
	int count = 0;

	printf("Input string ? ");
	scanf("%s", str);
	ptr = str;
	printf("%s \n", ptr);
	
	while (*ptr)
	{
		ptr++;
		count++;
	}
	printf("%d \n", count);
	
	do
	{
		ptr--;
		printf("%c \n", *ptr);
	} while (ptr != str);

	//for (; ptr != str; ptr--)
	//for (ptr = str+count; ptr != str; ptr--)
	//{
	//	count++;
	//	printf("%c \n", *ptr);
	//}
	//printf("%c \n", str[0]);
	// printf("%c \n", *(--ptr));

	return 0;
}
*/
