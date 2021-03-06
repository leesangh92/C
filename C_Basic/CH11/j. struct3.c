#include <stdio.h>
#include <string.h>

// 전역변수로 설정하면 모든 함수에서 사용할 수 있다. 
typedef struct EMPLOYEE {
	char name[20];
	int salary;
	float height;
	char comAddr[50];
} EMP;

//void funcA(struct EMPLOYEE emps);
void funcA(struct EMPLOYEE *emps);
struct EMPLOYEE funcB();

int main()
{
	
	struct EMPLOYEE emps = { "홍길동", 3800000, 172.5, "서울시 강남구" }, my;

	// funcA(emps); // call by value
	funcA(&emps); // call by reference

	printf("main emps : %s, %d, %.2f, %s \n", emps.name, emps.salary, emps.height, emps.comAddr);

	my = funcB();
	printf("main() my : %s, %d, %.2f, %s \n", my.name, my.salary, my.height, my.comAddr);

	return 0;
}

/* 
void funcA(struct EMPLOYEE emps) // call by value
{
	printf("funcA() : %s, %d, %.2f, %s \n", emps.name, emps.salary, emps.height, emps.comAddr);
	emps.salary += 300000; // 가인수의 변화는 실인수에 영향을 주지 않는다.
}
*/

void funcA(struct EMPLOYEE *emps) // call by reference
{
	printf("funcA() : %s, %d, %.2f, %s \n", emps->name, emps->salary, emps->height, emps->comAddr);
	emps->salary += 300000;
}

struct EMPLOYEE funcB()
{
	struct EMPLOYEE tmp;

	tmp.salary = 2700000;
	tmp.height = 163;
	//tmp.name = "진달래"; // name 배열 주소 = 문자열 상수(주소)
	//tmp.comAddr = "부산시 해운대구";
	strcpy(tmp.name, "진달래");
	strcpy(tmp.comAddr, "부산시 해운대구");

	printf("funcA() : %s, %d, %.2f, %s \n", tmp.name, tmp.salary, tmp.height, tmp.comAddr);

	return tmp;
}