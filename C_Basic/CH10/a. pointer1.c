#include <stdio.h>

// 포인터(pointer) : 실행 중인 프로세스의 임의 주소.

int main()
{
	double d; // 변수(값)
	// 포인터 변수의 타입은 자신이 참조할 데이터의 자료형과 같아야 한다. 
	double *dp; // 포인터 변수(메모리 주소)
	char *ptr;

	d = 1.5; // 실수형 double 8바이트 할당
	printf("%lf, %p \n", d, &d);

	dp = &d;
	printf("%lf, %p \n", *dp, dp); // 실행문의 '*' = 포인터 연산자 // 간접참조
	                    // -> 보관 중인 메모리 주소를 찾아간다. 

	printf("%d, %d, %d \n", sizeof(d), sizeof(dp), sizeof(ptr));
	//ptr = &d;
	printf("%p \n", ptr);
	//printf("%lf \n", *ptr);

	return 0;
}
