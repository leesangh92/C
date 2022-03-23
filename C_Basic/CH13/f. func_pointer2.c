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
typedef int (*FP)(int ,int); // 함수 포인터 자료형 선언 => 함수포인터를 typedef로 선언하면 함수포인터 변수가 아닌, 함수포인터 자료형이 된다. 

int main()
{
	int ret;

	ret = add(100, 30);
	printf("0. add() : %d \n\n", ret);

	// 1. 함수포인터 변수를 사용하여 sub 함수를 호출
	int (*fp1)(int, int);
	fp1 = sub;
	ret = (*fp1)(100, 30);
	printf("1. sub() : %d \n\n", ret);

	// 2. 재정의된 함수포인터 자료형으로 함수포인터 변수 선언
	FP fp2; // 함수포인터 변수 : 함수포인터 자료형명 함수포인터 변수명
	FP fp3;
	fp2 = add;
	fp3 = sub;
	printf("2. add() : %d \n", (*fp2)(100, 30));
	printf("2. sub() : %d \n\n", (*fp3)(100, 30));

	// 3. 재정의된 함수포인터 자료형으로 함수포인터 배열 선언
	FP fp4[5]; // 함수포인터 배열
	fp4[0] = add;
	fp4[1] = sub;
	printf("3. add() : %d \n", (*fp4[0])(100, 30));
	printf("3. sub() : %d \n\n", (*fp4[1])(100, 30));

	// 4. 함수를 호출할 때 함수 주소를 실인수로 전달
	funCalc(add);
	funCalc(sub);


	return 0;
}
/*
void funCalc(int (*fp5)(int, int)) // 4. 가인수가 함수포인터 변수
{
	printf("4. funCalc() : %d \n", (*fp5)(100, 30));
}
*/

void funCalc(FP fp5) 
{
	printf("4. funCalc() : %d \n", (*fp5)(100, 30));
}