#include <stdio.h>
#include <string.h>

// 포인터 배열

int main()
{
	char s1[20] = "kingdom", s2[20], s3[20], s4[20];

	strcpy(s2, s1);
	printf("s1 : %s, s2 : %s \n", s1, s2);

	myStrcpy(s3, s1);
	printf("s1 : %s, s3 : %s \n", s1, s3);

	strcpy(s4, "Hello World!!!"); // "" : 문자열 상수 // char *strcpy(char* strDestination, const char* strSource);
	printf("s4 : %s", s4);

	return 0;
}

// char *strcpy(char* strDestination, const char* strSource);
myStrcpy(char *to, char *from)
{
	while (*from)
	{
		*to = *from;
		to++, from++;
	}
	*to = '\0'; // from의 주소에 있는 null 데이터를 받으면 while문을 빠져나오게 되고 to 메모리 주소의 남은 공간에는 쓰레기 데이터로 채워지게 된다.
				// 따라서 to 메모리 주소의 마지막 값을 null 값으로 준다.
	// *to = "\0" -> 1byte = 2byte 이므로 에러
}