#include <stdio.h>

void myFunc(char* tmp);

int main()
{
	void (*fptr)(char *); // �Լ� ������ ���� ���� 
						  // call back �Լ� ���� �ݵ�� �ʿ��ϴ�.
						  // ������ Ÿ��(�������� �����ص� �ȴ�), ��Ÿ�� // ���� => ������ Ÿ��, ���๮ => ��Ÿ��

	printf("fptr size : %d \n", sizeof(fptr));

	fptr = myFunc; // �Լ� �ּ� �Ҵ�
	
	(*fptr)("Multi Campus"); // �Լ� ȣ��
	fptr("���Ǵ�Ʈ �ｺ�ɾ�"); // => 15 ��� ���� ����
	//myFunc("this is a test.");

	return 0;
}

void myFunc(char *tmp)
{
	printf("myFunc() : %p, %s \n", tmp, tmp);
}