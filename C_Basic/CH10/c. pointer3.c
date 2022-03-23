#include <stdio.h>
#include <string.h>

int main()
{
	int num[5] = { 100, 200, 300, 400, 500 };
	int i, *ptr; // *ptr : 포인터 변수 -> 포인터 상수와는 다르게 변경이 가능하다. 

	ptr = num;
	
	printf("\n");
	for (i = 0; i < 5; i++)
		//printf("%p, %d, %d \n", &num[i], num[i], *(num+ i));
		//printf("%d, %d, %d \n", num + i, num[i], *(num + i)); // 첨자가 없는 배열 변수는 그 배열의 시작주소를 나타낸다. 
		//printf("%p, %d, %d \n", &num[i], num[i], *(ptr + i));
		//printf("%p, %d, %d \n", &num[i], num[i], *ptr + i);
		printf("%p, %d, %d, %d \n", num + i, num[i], *(ptr + i), *(num + i), ptr[i]);
		printf("\n");



	char str[20] = "kingdom", * p2;

	p2 = str;
	printf("%c, %c, %c, %c \n", str[0], *(str + 0), *(str + 1), *p2); // 데이터
	printf("&p, %s, %s \n", str, str, p2);                            // 주소

	/*
	p2를 사용하여 k, i, n, g, d, o, m 을 출력
	*/
	
	for (i = 0; i < strlen(p2); i++)
	{
		printf("%d. *(p2+i) : %c \n", i, *(p2+i)); // *(p2+i) , *p2+i 의 차이  // 주소 하나씩 증가
		//printf("%d. *p2+i : %c \n", i, *p2+i); // 알파벳 문자 하나씩 증가
	}
	
	
	while(*p2) // \n(null)값을 만나면 0으로 거짓이 되어 루프가 끝난다. while(p2)이면 무한루프. while(*str)
	{
		printf("%c, ", *p2);
		//printf("%c, ", *str);
		p2++;
		//str++; // 첨자가 없는 배열 변수는 그 배열이 할당된 메모리의 시작주소를 갖는 포인터 상수이다. 변경이 불가능하다!!!
	}

	return 0;
}