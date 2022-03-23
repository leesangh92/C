#include <stdio.h>

int main()
{
	int num[3] = { 100, 200, 300 }, i;
	int *p1[3]; // 포인터 배열
	//char* p2[5] = { "kingdom", "Multi Campus", "Hello World!!!", "one 하나", "two 둘" };
	char* p2[] = { "kingdom", "Multi Campus", "Hello World!!!", "one 하나", "two 둘" , "seoul 서울시 강남구 역삼동", "busan 부산시 해운대구 해운대동", NULL };
	// unsigned 포인터배열은 반드시 초기화가 되어야한다.

	//printf("sizeof p1 : %d \n", sizeof(p1));
	printf("sizeof p2 : %d \n", sizeof(p2));

	for (i = 0; p2[i]; i++)
		printf("%p, %s \n", p2[i], p2[i]);

	/*
	// p1 주소 저장
	for (i = 0; i < 3; i++)
		p1[i] = num + i;

	// p1을 사용하여 100, 200, 300을 출력
	for (i = 0; i < 3; i++)
		printf("%d, ", *p1[i]);
	printf("\n");
	*/

	return 0;
}