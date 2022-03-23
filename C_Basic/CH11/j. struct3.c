#include <stdio.h>
#include <string.h>

// ���������� �����ϸ� ��� �Լ����� ����� �� �ִ�. 
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
	
	struct EMPLOYEE emps = { "ȫ�浿", 3800000, 172.5, "����� ������" }, my;

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
	emps.salary += 300000; // ���μ��� ��ȭ�� ���μ��� ������ ���� �ʴ´�.
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
	//tmp.name = "���޷�"; // name �迭 �ּ� = ���ڿ� ���(�ּ�)
	//tmp.comAddr = "�λ�� �ؿ�뱸";
	strcpy(tmp.name, "���޷�");
	strcpy(tmp.comAddr, "�λ�� �ؿ�뱸");

	printf("funcA() : %s, %d, %.2f, %s \n", tmp.name, tmp.salary, tmp.height, tmp.comAddr);

	return tmp;
}