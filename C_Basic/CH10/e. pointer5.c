#include <stdio.h>
#include <string.h>

// ������ �迭

int main()
{
	char s1[20] = "kingdom", s2[20], s3[20], s4[20];

	strcpy(s2, s1);
	printf("s1 : %s, s2 : %s \n", s1, s2);

	myStrcpy(s3, s1);
	printf("s1 : %s, s3 : %s \n", s1, s3);

	strcpy(s4, "Hello World!!!"); // "" : ���ڿ� ��� // char *strcpy(char* strDestination, const char* strSource);
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
	*to = '\0'; // from�� �ּҿ� �ִ� null �����͸� ������ while���� ���������� �ǰ� to �޸� �ּ��� ���� �������� ������ �����ͷ� ä������ �ȴ�.
				// ���� to �޸� �ּ��� ������ ���� null ������ �ش�.
	// *to = "\0" -> 1byte = 2byte �̹Ƿ� ����
}