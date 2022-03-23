#include <stdio.h>
#include <stdlib.h> 

int main()
{
	FILE* fp;
	char str[20] = "kingdom", tmp[20];

	//Save
	/*
	fp = fopen("data2.txt", "wt");
	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	fputs(str, fp);

	fclose(fp);
	*/

	//Load
	fp = fopen("data2.txt", "rt");
	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	fgets(tmp, 20, fp);

	fclose(fp);

	printf("tmp : %s \n", tmp);

	return 0;
}