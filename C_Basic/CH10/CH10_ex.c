/*
#include <stdio.h>

int main()
{
	char ch, * cp;
	int num, * ip;
	float f_num, * fp;
	double d_num, * dp;

	printf(" 변수의 크기 : %3d, %3d, %3d, %3d \n", sizeof(ch), sizeof(num), sizeof(f_num), sizeof(d_num));
	printf(" 포인터 변수의 크기 : %3d, %3d, %3d, %3d \n", sizeof(cp), sizeof(ip), sizeof(fp), sizeof(dp));

	d_num = 17.5;
	cp = &d_num; // 자료형이 다르다 -> 값을 불러올 수 없다

	printf("\n cp가 참조한 값 : %lf \n\n", *cp);

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

	printf("변수들의 시작 주소 : %p, %p, %p, %p \n", &ch, &num, &f_num, &d_num);
	printf("변수들의 값 :       %5c,   %5d, %10.2f, %10.2lf \n\n", ch, num, f_num, d_num);

	printf("포인터 변수에 저장된 주소 : %p, %p, %p, %p \n", cp, ip, fp, dp);
	printf("변수들의 값 :               %5c,  %5d, %10.2f, %10.2lf \n", *cp, *ip, *fp, *dp);


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

	printf("변수와 포인터 변수 \n");
	printf("변수들의 값 :             %5c,    %5d,%10.2f, %10.2lf \n", ch, num, f_num, d_num);
	printf("포인터 변수에 저장된 주소 : %p, %p, %p, %p \n\n", cp, ip, fp, dp);

	ch++; num++; f_num++; d_num++;
	cp++; ip++; fp++; dp++;

	printf("+1 된 변수와 포인터 변수 \n");
	printf("변수들의 값 :               %5c,  %5d, %10.2f, %10.2lf \n", ch, num, f_num, d_num);
	printf("포인터 변수에 저장된 주소 : %p, %p, %p, %p \n\n", cp, ip, fp, dp);

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

	printf("배열의 시작 주소 : %p, %p, %p \n\n", count, &count[0], ptr);

	printf("첨자를 이용한 출력 : ");
	for (i = 0; i < 6; i++)
	{
		printf("%d, ", count[i]);
	}
	printf("\n\n");

	printf("배열변수를 이용한 포인터연산 : ");
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

	printf("포인터변수를 이용한 포인터연산 : ");
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
	char* msg = "Advanced C."; // *msg 라는 메모리 주소를 할당하고, "Advanced C." 문자열 상수 시작 주소를 저장한다

	printf("str : %s, msg : %s \n", str, msg);

	strcpy(str, msg); // msg 주소의 문자열을 str 배열에 복사한다.
	printf("str : %s, msg : %s \n", str, msg);

	printf("input string ? :");
	gets(str);
	
	//strcpy(msg, str); // str 배열의 문자열을 msg에 저장된 시작주소 메모리에 복사 => msg가 가리키는 메모리는 읽기전용 메모리 
	//printf("str : %s, msg : %s \n", str, msg); // 런타임 오류
	
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

	printf("count 배열의 시작주소 : %p, 배열의 크기 : %d \n\n", count, sizeof(count));

	func1(count);
	printf("count 배열의 값 : ");
	for (i = 0; i < 5; i++)
		printf("%d ", count[i]);
	printf("\n\n");

	return 0;
}

void func1(int* ptr)
{
	int i;
	printf("func1() 포인터변수가 저장한 시작주소 : %p, 포인터변수의 크기 : %d \n\n", ptr, sizeof(ptr));

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

	printf("성명 : 홍길동 \n");
	printf("기본급 : %d \n", *sal);
	printf("수당(기본급의 15%%) : %.0f \n", (*sal) * 0.15);
	printf("실수령액(기본급 + 수당) : %.0f \n", *sal + ((*sal) * 0.15));

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
	const int* ptr = &num; // const 상수화된 데이터

	printf("*ptr : %d \n", *ptr);
	// *ptr = 200; 
}
*/

/*
키보드로부터 문자열을 입력받아 이를 반대로 (끝에서부터) 출력하는 프로그램을 포인터를 이용하여 작성.
또한 문자열의 크기를 구하여 함께 출력.(strlen() 함수 사용X)
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
