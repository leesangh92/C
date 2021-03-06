#include <stdio.h>

// 구조체(Struct) : 관련이 있는 데이터들을 하나의 자료형으로 만들어 사용 가능하게 한다. 즉, 사용자 정의 자료형을 만든다. 

int main()
{
	// 사용자 정의 자료형
	struct EMPLOYEE
	{   // 멤버리스트
		char name[20];
		int salary;
		float height;
		char comAddr[50];
	}; //tmp;
	
	//int salary = 1000;
	struct EMPLOYEE emps; // = {"홍길동", 3800000, 172.5, "서울시 강남구" }; // 구조체 변수(통합 자료형 변수)

	//typedef struct EMPLOYEE EMP;
	//EMP tmp;
	struct EMPLOYEE tmp;



	printf("%d, %d \n", sizeof(emps), sizeof(struct EMPLOYEE)); // 구조체 크기는 sizeof() 연산자를 통해 확인한다. 데이터 재배열
	//printf("%d, %d \n", sizeof(tmps);
	//printf("%d \n", salary); // 변수
	//printf("%d \n", emps.salary); // . : 구조체 멤버 연산자 // 멤버 (변수 != 멤버)



	printf("성명 ? ");
	gets(emps.name);

	printf("월급 ? ");
	scanf("%d%*c", &emps.salary);

	printf("키(신장) ? ");
	scanf("%f%*c", &emps.height);

	printf("회사주소 ? ");
	gets(emps.comAddr);

	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary, emps.height, emps.comAddr);



	tmp = emps; // 구조체 변수 복사 // 배열 복사는 안된다. 변수 복사는 된다.(단, Type이 같으면) 
	printf("%s, %d, %.2f, %s \n", tmp.name, tmp.salary, tmp.height, tmp.comAddr);


	return 0;
}
