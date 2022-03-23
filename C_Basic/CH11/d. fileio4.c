#include <stdio.h>
#include <stdlib.h> 

int main()
{
	FILE* fp;
	char tmp[80];

	fp = fopen("c:\\temp\\datatype1.c", "rt");

	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1);
	}

	while (1)
	{
		if (fgets(tmp, 80, fp))
			printf("%s : ", tmp);
		else
			break;
	}

	fclose(fp);

	return 0;
}