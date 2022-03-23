#include <stdio.h>
#include <stdlib.h> 

struct STUDENT
{
	char name[20];
	int kor;
	int eng;
	int mat;
	float avg;
};
int main()
{
	FILE* fp;
	struct STUDENT stu[3] =
	{ 
		{ "���޷�", 89, 100, 30 }, 
		{ "�̸���", 100, 75, 50 }, 
		{ "������", 68, 83, 67 } 
	};
	struct STUDENT tmp;
	
	// Save
	fp = fopen("data4.dat", "ab"); // dataŸ��, write binary(wb)

	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	// stu.avg = (float)(stu.kor + stu.eng + stu.mat) / 3;

	// �� �� �ϳ� �����ؼ� ���
	//fwrite(stu, sizeof(stu), 1, fp); // �޸� ũ�Ⱑ �������� �ڷ��� �����ڸ� ������ ���� �ʿ䰡 ����. �ӵ��� ������ // �޸� �ּҿ� ũ�⸸ �˸� �ȴ�.
	fwrite(stu, sizeof(struct STUDENT), 3, fp); // -> ��ȣ

	fclose(fp);
	
	
	// Load
	fp = fopen("data4.dat", "rb"); // dataŸ��, read binary(rb)

	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	while (1)
	{
		if (fread(&tmp, sizeof(struct STUDENT), 1, fp) != 1) // �޸� ũ�Ⱑ �������� �ڷ��� �����ڸ� ������ ���� �ʿ䰡 ����. �ӵ��� ������ // �޸� �ּҿ� ũ�⸸ �˸� �ȴ�. 
			break;

		printf("%s, %d, %d, %d, %.2f ", tmp.name, tmp.kor, tmp.eng, tmp.mat, tmp.avg);
	}
	
	fclose(fp);

	return 0;
}