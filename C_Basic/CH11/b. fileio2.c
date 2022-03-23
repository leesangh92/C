#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{
	char ch;
	FILE* in, *out;

	/*
	in = fopen("data1.txt", "rt"); 
	if (in == NULL)
	{
		printf("in stream error. \n");
		exit(1); 
	}
	*/
	
	in = fopen(argv[1], "rt");
	if (in == NULL)
	{
		printf("in stream error. \n");
		exit(1);
	}

	/*
	out = fopen("data1.bak", "wt");
	if (out == NULL)
	{
		printf("out stream error. \n");
		exit(1);
	}
	*/

	out = fopen(argv[2], "wt");
	if (out == NULL)
	{
		printf("out stream error. \n");
		exit(1);
	}

	// 파일 복사
	while ((ch = fgetc(in)) != EOF)
		fputc(ch, out);

	fclose(in);
	fclose(out);

	printf("data1.bak 파일 복사. \n");

	return 0;
}