#include <stdio.h>

void salCal(int* tmp, int size);
int* funcA();

int main()
{
	//int salary[5] = { 1500, 3000, 4500, 7000, 2700 }, i;
	int salary[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, i; // unsized 배열(마지막에 null 값이 없다) // 반드시 초기화를 해주어야한다. 
	int size;

	size = sizeof(salary) / sizeof(salary[0]);

	printf("%d \n", salary[0]);
	//salCal(salary[0]); // 직접 불러오기, 값에 의한 호출, call by value (개수에 한계가 있음) : 값을 불러온다. 
	//salCal(salary); // 참조에 의한 호출, call by reference(가인수의 변화가 실인수에 영향을 미친다)
	salCal(salary, size);



	int* sudang;

	sudang = funcA();
	printf("main() 수당 : %d \n", *sudang);



	funcB();



	funcD();

	return 0;
}

funcD()
{
	//char *p1;
	char* p1 = "!!!World Hello";

	p1;
	//p1 = "Hello World!!!"; // 문자열 상수 포인터
	printf("p1 : %p, %s \n", p1, p1);
}

funcB()
{
	const float PI = 3.14159; // 변수를 상수화

	int n1 = 100, n2 = 200;

	int* p1 = &n1;
	*p1 = 150;
	printf("\nfuncB() n1 : %d \n", n1);

	const int* p2 = &n2; // 포인터를 상수화
	//*p2 = 250; // const 상수로 p2 메모리 주소에 있는 데이터 내용을 바꿀 수 없다. 
	printf("\nfuncB() n2 : %d \n", n2);
}

int *funcA()
{
	static int su; // 정적변수. 그냥 int su;를 사용했을때 su는 지역변수로 다른 데이터가 해당 메모리 주소에 들어가면 *sudang의 출력값이 변한다.(정적변수를 사용한 이유)
	printf("수당 ? ");
	scanf("%d", &su);

	return &su; // return변수가 포인터이면 받는 변수도 포인터이다.
}

//salCal(int tmp[9], int size) // 대괄호 안의 숫자는 상관없음
//salCal(int tmp[], int size)
void salCal(int *tmp, int size)//salCal(int tmp) // 월급의 평균을 계산하여 출력
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
	printf("\n평균 : %f \n", (float)salTot/5);
	*/
	for (i = 0; i < size; i++)
	{
		//printf("%d, ", tmp[i]);
		printf("%d, ", *(tmp + i));
		//salTot += tmp[i];
		salTot += *(tmp + i);
	}
	printf("\n평균 : %f \n", (float)salTot / size);
	/*
	*tmp += 1000;
	printf("%d \n", *tmp);
	*/
}