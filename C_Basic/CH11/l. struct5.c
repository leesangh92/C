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

	struct EMPLOYEE emps = { "ȫ�浿", 3800000, 172.5, "����� ������" }, my;

	struct EMPLOYEE* ptr; // ����ü ������ ����, ������ �ڷ������� ������� �����ͺ����� ũ��� �ü���� ���� �����ȴ�. 

	printf("%d, %d \n", sizeof(emps), sizeof(ptr));

	ptr = &emps;

	// -> : ����ü ������ ������
	printf("%s, %d, %.2f, %s \n", ptr->name, ptr->salary, (*ptr).height, (*ptr).comAddr); // ����ü ������ �����ڸ� ����� ���� �ְ� ������ ������� �״�� �� ���� �ִ�. 
	
	return 0;
}
