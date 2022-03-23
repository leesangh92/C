#include <stdio.h>

int main()
{
	int num;
	int * ip; // 단일 포인터 : 변수의 시작 주소를 저장
	int ** mip; // 다중 포인터 : 포인터 변수의 시작 주소를 저장

	printf("%d, %d, %d \n", sizeof(num), sizeof(ip), sizeof(mip));

	ip = &num;
	mip = &ip;

	**mip = 500;

	printf("%d, %d, %d \n\n", num, *ip, **mip);




	char* ptr[] = { "kingdom", "Multi Campus", "Hello World!!!", "one 하나", "two 둘" , "seoul 서울시 강남구 역삼동", "busan 부산시 해운대구 해운대동", NULL };

	funcA(ptr);

	return 0;
}

// ptr에 저장된 문자열 출력
funcA(char **tmp)
{
	int len = 0;
	char* ptr;

	printf("funcA() : %p, %d \n\n", tmp, sizeof(tmp));

	while (*tmp) 
	{
		ptr = *tmp;
		while (*ptr)
		{
			len++;
			ptr++;
		}

		printf("%u : %u, %s, Length : %d \n", tmp, *tmp, *tmp, len);
		len = 0;

		tmp++;
	}
	/*
	while (1)
		if (*tmp != 0)
			printf("%s \n", *tmp);

	printf("%u : %u, %s, %s \n", tmp, *tmp, *tmp, **tmp);
	*/
}