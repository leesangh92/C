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
		{ "진달래", 89, 100, 30 }, 
		{ "이몽룡", 100, 75, 50 }, 
		{ "성춘향", 68, 83, 67 } 
	};
	struct STUDENT tmp;
	
	// Save
	fp = fopen("data4.dat", "ab"); // data타입, write binary(wb)

	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	// stu.avg = (float)(stu.kor + stu.eng + stu.mat) / 3;

	// 둘 중 하나 선택해서 사용
	//fwrite(stu, sizeof(stu), 1, fp); // 메모리 크기가 기준으로 자료형 지정자를 일일히 적을 필요가 없다. 속도가 빠르다 // 메모리 주소와 크기만 알면 된다.
	fwrite(stu, sizeof(struct STUDENT), 3, fp); // -> 선호

	fclose(fp);
	
	
	// Load
	fp = fopen("data4.dat", "rb"); // data타입, read binary(rb)

	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	while (1)
	{
		if (fread(&tmp, sizeof(struct STUDENT), 1, fp) != 1) // 메모리 크기가 기준으로 자료형 지정자를 일일히 적을 필요가 없다. 속도가 빠르다 // 메모리 주소와 크기만 알면 된다. 
			break;

		printf("%s, %d, %d, %d, %.2f ", tmp.name, tmp.kor, tmp.eng, tmp.mat, tmp.avg);
	}
	
	fclose(fp);

	return 0;
}