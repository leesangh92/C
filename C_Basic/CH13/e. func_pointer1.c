#include <stdio.h>

void myFunc(char* tmp);

int main()
{
	void (*fptr)(char *); // 함수 포인터 변수 선언 
						  // call back 함수 에서 반드시 필요하다.
						  // 컴파일 타임(변수명은 생략해도 된다), 런타임 // 선언문 => 컴파일 타임, 실행문 => 런타임

	printf("fptr size : %d \n", sizeof(fptr));

	fptr = myFunc; // 함수 주소 할당
	
	(*fptr)("Multi Campus"); // 함수 호출
	fptr("인피니트 헬스케어"); // => 15 행과 같은 형태
	//myFunc("this is a test.");

	return 0;
}

void myFunc(char *tmp)
{
	printf("myFunc() : %p, %s \n", tmp, tmp);
}