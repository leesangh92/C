#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 전역변수로 head, tail

#define BUF_SIZE 50

typedef struct employee 
{
	char id[6];
	char name[20];
	int position;
	int salary;
	char comAddr[BUF_SIZE];
	struct employee* next;
} EMPLOYEE, * LPEMPLOYEE; // 구조체 자료형명, 구조체 포인터 자료형명

//struct employee a, * head;
EMPLOYEE a, * head;
LPEMPLOYEE tail;

int seq_no = 0;

void str_check(char* msg, int size, char* f_addr);
void num_check(char* msg, int max, int min, int* f_addr);
void emp_input();
char* showPosition(int pos);
void emp_output();
void emp_find();
void emp_delete();
void emp_save();
void emp_load();
void node_free();


//"성명", 20, 3006
//"회사주소", 50, 3034
void str_check(char* msg, int size, char* f_addr)
{
	char tmp[255];

	do 
	{
		printf("%s ? ", msg);
		gets(tmp); //seoul aaaaaaaaaaaaaaaaaaaaaaaaaaaa, kim ??
	} while (strlen(tmp) >= size);

	strcpy(f_addr, tmp);
}

//"직급", 3, 0, 3026
//"월급", 7000000, 0, 3030
void num_check(char* msg, int max, int min, int* f_addr)
{
	int tmp = 10;

	do
	{
		printf("%s ? ", msg);
		scanf("%d%*c", &tmp);
	} while (tmp < min || tmp > max);

	*f_addr = tmp;
}

void emp_input()
{
	EMPLOYEE* ptr;

	while (1)
	{
		ptr = (EMPLOYEE*)malloc(sizeof(struct employee));
		if (ptr == NULL)
		{
			perror("Error ");
			exit(1);
		}

		seq_no++;
		// 코드추가
		sprintf(ptr->id, "A%.4d", seq_no); // A 로 시작, 4자리가 안되면 0을 채워넣는다.

		str_check("\n성명(입력종료:end)", sizeof(ptr->name), ptr->name);

		if (!strcmp(ptr->name, "end"))
		{
			seq_no--;
			break;
		}

		num_check("직급(0:부장,1:과장,2:대리,3:사원)", 3, 0, &ptr->position); // 입력받는 정수의 조건 제한
		//printf("직급(0:부장,1:과장,2:대리,3:사원) ? ");
		//scanf("%d%*c", &ptr->position);

		num_check("월급", 7000000, 0, &ptr->salary);
		//printf("월급 ? ");
		//scanf("%d%*c", &ptr->salary);

		str_check("회사주소", sizeof(ptr->comAddr), ptr->comAddr);

		ptr->next = NULL;

		//코드입력
		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	}

	free(ptr);
}//emp_input() end

char* showPosition(int pos) // 직급(0:부장,1:과장,2:대리,3:사원)
{
	if (pos == 0)
		return "부장";
	else if (pos == 1)
		return "과장";
	else if (pos == 2)
		return "대리";
	else
		return "사원";

	//static char POS[4][20] = { "부장","과장","대리","사원" }; // 함수를 벗어나면 메모리가 해제된다. 때문에 static으로 메모리 해제를 막는다.

	//return POS[pos]; 
}

void emp_output()
{
	EMPLOYEE* ptr;

	ptr = head;
	while (ptr)
	{
		printf("%s, %s, %s, %d, %s \n", ptr->id, ptr->name, showPosition(ptr->position), ptr->salary, ptr->comAddr); // 함수 안의 함수. 안쪽 함수부터 실행

		ptr = ptr->next;
	}
}//emp_output() end

void emp_find()
{
	EMPLOYEE* ptr;
	int found;
	char s_name[20];

	ptr = head;
	if (ptr == NULL)
	{
		printf(" 등록되어 있지 않습니다. \n");
		return;
	}

	while (1)
	{
		printf("\n검색할 성명 ? (검색종료:end) ");
		gets(s_name);
		if (!strcmp(s_name, "end"))
			break;

		found = 1;
		ptr = head;

		while (ptr)
		{
			if (!strcmp(ptr->name, s_name))
			{
				found = 0;
				printf("%s, %s, %d, %d, %s \n", ptr->id, ptr->name, ptr->position, ptr->salary, ptr->comAddr);
			}
			ptr = ptr->next;
		}

		if (found)
			printf("%s, Not found !!\n", s_name);

	} //while(1) end

}//emp_find() end

void emp_delete() // 노드 삭제 시에는 참조할 주소를 다른 주소에 맵핑해두고 메모리를 해제시켜야 한다.
{
	EMPLOYEE* ptr, * prev;
	int found;
	char ch, s_id[10];

	ptr = head;
	if (ptr == NULL)
	{
		printf("등록되어 있지 않습니다. \n");
		return;
	}

	printf("\n삭제할 ID ? ");
	gets(s_id); //A0001, A0005, A0003

	*s_id = toupper(*s_id);

	// 코드추가
	found = 1;
	while (ptr)
	{
		if (!strcmp(ptr->id, s_id))
		{
			printf("%s, %s, %d, %d, %s \n", ptr->id, ptr->name, ptr->position, ptr->salary, ptr->comAddr);

			printf("삭제할까요 ? (y/n) ");
			scanf("%c%*c", &ch);

			if (ch == 'Y' || ch == 'y')
			{
				// 삭제 알고리즘
				if (ptr == head)
				{
					head = ptr->next;
				}
				else if (ptr == tail)
				{
					tail = prev;
					tail->next = NULL;
				}
				else
				{
					prev->next = ptr->next;
				}
				free(ptr);
				found = 0;
			}
			break; // 자신이 속한 '반복문'을 나간다.(while(ptr) End. 로 간다) // 없어도 되지만 없다면 불필요한 로직을 반복하게 된다.
		}
		prev = ptr;
		ptr = ptr->next;
	} // while (ptr) End.

	if (found)
		printf("노드삭제 안 됨!!!\n"); 
	else
		printf("노드삭제 됨!!!\n");

}//emp_delete() end

void node_free()
{
	EMPLOYEE* ptr, * x;

	ptr = head;
	while (ptr)
	{
		x = ptr;
		ptr = ptr->next;

		free(x);
	}
}//node_free() end

void emp_save(void) // seq_no와 노드를 저장한다. 
{
	EMPLOYEE* ptr;
	FILE* fp;

	ptr = head;
	if (ptr == NULL)
	{
		printf("등록되어 있지 않습니다. \n");
		return;
	}

	fp = fopen("s_emp.dat", "wb");
	if (fp == NULL)
	{
		perror("emp_save() ");
		exit(1);
	}

	fwrite(&seq_no, sizeof(int), 1, fp); // fwrite(저장할 함수 주소, 저장할 크기, 개수, 파일스트림)

	while (ptr)
	{
		fwrite(ptr, sizeof(EMPLOYEE), 1, fp);
		ptr = ptr->next;
	}
	fclose(fp);

	printf("사원정보 save. \n");
} //emp_save() end

void emp_load(void)
{
	struct employee* ptr;
	FILE* fp;

	fp = fopen("s_emp.dat", "rb");
	if (fp == NULL)
	{
		perror("emp_load() ");
		return;
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		ptr = (EMPLOYEE*)malloc(sizeof(EMPLOYEE)); // 동적 메모리 준비 !!! // 메모리 시작주소가 동일한 규칙으로 배정되는가? 아니면 랜덤하게 배정되는가?
		if (ptr == NULL)
		{
			perror("emp_load() ");
			exit(1);
		}

		if (fread(ptr, sizeof(EMPLOYEE), 1, fp) != 1)
			break;

		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	}
	fclose(fp);
	free(ptr);

	printf("사원정보 load. \n");
} //emp_load() end

int main()
{
	int choice, stop = 1, count;

	head = tail = NULL;
	//emp_load();

	while (stop)
	{
		printf("\n1. 사원정보 입력 \n");
		printf("2. 사원정보 출력 \n");
		printf("3. 사원정보 검색 \n");
		printf("4. 사원정보 삭제 \n");
		printf("5. 사원정보 저장 \n");
		printf("6. 프로그램 종료 \n");
		printf("Select ? (1~6) ");
		scanf("%d%*c", &choice);
		switch (choice)
		{
		case 1: emp_input();
			break;
		case 2: emp_output();
			break;
		case 3: emp_find();
			break;
		case 4: emp_delete();
			break;
		case 5: emp_save();
			break;
		case 6: node_free();
			stop = 0;
			break;
		}
	}

	return 0;
}//main() end

// 데이터 순서 변경하기?
// 저장된 파일을 수정하는 방법? 데이터파일을 직접 수정 / 코드로 오픈하여 수정 후 저장