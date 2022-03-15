#include <stdio.h>
#include <stdlib.h> // exit 함수가 포함되어 있다. 

// main함수의 부모함수 = O/S(운영체제)
// O/S => 프로세스 종료 exit code(0 : 성공, not 0 : 실패)
int main()
{
	char ch;
	FILE* fp; // 구조체 FILE : <stdio.h> 라이브러리에 포함되어 있다. 

	/*
	// SAVE
	// 1. 스트림 연결
	fp = fopen("data1.txt", "wt"); // fopen(오픈할 파일명, 오픈 모드(wt(w) : write text)) // data1.txt.파일이 없으면 만들기, 있으면 overwrite
	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1); // 프로그램 즉시 종료 함수, 괄호 안에 0~255사이의 임의의 수를 넣어준다. 무엇을 넣든 프로그램 종료된다. 프로세스 종료 exit code(0 : 성공, not 0 : 실패)
	}
	// 2. 파일 입출력 함수로 save/load
	puts("stdin -> disk");
	while ((ch = fgetc(stdin)) != EOF) // EOF = ctrl+z(^Z) 하면 종료
		fputc(ch, fp);
	
	// 3. 스트림 닫기
	fclose(fp);
	*/

	// SAVE
	// 1. 스트림 연결
	fp = fopen("data1.txt", "at"); // fopen(오픈할 파일명, 오픈 모드(at(a) : append text))
	if (fp == NULL)
	{
		printf("file open error. \n");
		exit(1); // 프로그램 즉시 종료 함수, 괄호 안에 0~255사이의 임의의 수를 넣어준다. 무엇을 넣든 프로그램 종료된다. 프로세스 종료 exit code(0 : 성공, not 0 : 실패)
	}
	// 2. 파일 입출력 함수로 save/load
	puts("stdin -> disk");
	while ((ch = fgetc(stdin)) != EOF) // EOF = ctrl+z(^Z) 하면 종료
		fputc(ch, fp);

	// 3. 스트림 닫기
	fclose(fp);



	// LOAD
	// 1. 스트림 연결
	fp = fopen("data1.txt", "rt"); // fopen(오픈할 파일명, 오픈 모드(rt : read text)) 
	if (fp == NULL) // data1.txt 파일이 있어야 한다. 없으면 file open error
	{
		printf("file open error. \n");
		exit(1);
	}
	// 2. 파일 입출력 함수로 save/load
	puts("disk -> stdout");
	while ((ch = fgetc(fp)) != EOF) // FILE 구조체의 마지막에 EOF가 포함되어있다. 
		fputc(ch, stdout);

	// 3. 스트림 닫기
	fclose(fp);

	return 0;
}
