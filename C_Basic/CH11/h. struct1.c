#include <stdio.h>

// ����ü(Struct) : ������ �ִ� �����͵��� �ϳ��� �ڷ������� ����� ��� �����ϰ� �Ѵ�. ��, ����� ���� �ڷ����� �����. 

int main()
{
	// ����� ���� �ڷ���
	struct EMPLOYEE
	{   // �������Ʈ
		char name[20];
		int salary;
		float height;
		char comAddr[50];
	}; //tmp;
	
	//int salary = 1000;
	struct EMPLOYEE emps; // = {"ȫ�浿", 3800000, 172.5, "����� ������" }; // ����ü ����(���� �ڷ��� ����)

	//typedef struct EMPLOYEE EMP;
	//EMP tmp;
	struct EMPLOYEE tmp;



	printf("%d, %d \n", sizeof(emps), sizeof(struct EMPLOYEE)); // ����ü ũ��� sizeof() �����ڸ� ���� Ȯ���Ѵ�. ������ ��迭
	//printf("%d, %d \n", sizeof(tmps);
	//printf("%d \n", salary); // ����
	//printf("%d \n", emps.salary); // . : ����ü ��� ������ // ��� (���� != ���)



	printf("���� ? ");
	gets(emps.name);

	printf("���� ? ");
	scanf("%d%*c", &emps.salary);

	printf("Ű(����) ? ");
	scanf("%f%*c", &emps.height);

	printf("ȸ���ּ� ? ");
	gets(emps.comAddr);

	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary, emps.height, emps.comAddr);



	tmp = emps; // ����ü ���� ���� // �迭 ����� �ȵȴ�. ���� ����� �ȴ�.(��, Type�� ������) 
	printf("%s, %d, %.2f, %s \n", tmp.name, tmp.salary, tmp.height, tmp.comAddr);


	return 0;
}
