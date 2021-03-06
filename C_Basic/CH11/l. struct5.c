#include <stdio.h>
#include <string.h>

typedef struct EMPLOYEE {
	char name[20];
	int salary;
	float height;
	char comAddr[50];
} EMP;

int main()
{

	struct EMPLOYEE emps = { "홍길동", 3800000, 172.5, "서울시 강남구" }, my;

	struct EMPLOYEE* ptr; // 구조체 포인터 변수, 변수의 자료형과는 상관없이 포인터변수의 크기는 운영체제에 의해 결정된다. 

	printf("%d, %d \n", sizeof(emps), sizeof(ptr));

	ptr = &emps;

	// -> : 구조체 포인터 연산자
	printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, (*ptr).height, (*ptr).comAddr); // 구조체 포인터 연산자를 사용할 수도 있고 포인터 연산식을 그대로 쓸 수도 있다. 
	
	return 0;
}
