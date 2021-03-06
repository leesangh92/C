#include <stdio.h>

int resize = 5;
int top = -1;
int *stack;

push(int value)
{
	if (top >= resize - 1) // 정해진 메모리 크기에 저장된 stack
	{
		resize += 5; // Heap 세그먼트의 메모리 변경
		//stack = (int*)realloc(stack, sizeof(resize * (sizeof(int))));
		stack = (int*)realloc(stack, sizeof(resize * (sizeof(int))));

		if (stack == NULL)
		{
			perror("Error ");
			exit(1);
		}
		printf("resize : %d, top : %d \n", resize, top);
	}
	stack[++top] = value;
}

pop()
{
	if (top == -1) // stack에 남아있는 값이 없는지 확인
	{
		printf("Stack empty !!! \n");
		return -1;
	}
	return stack[top--];
}

int main()
{
	int N;

	//stack = (int*)malloc(sizeof(resize * (sizeof(int))));
	stack = (int*)malloc(resize * sizeof(int));
	if (stack == NULL)
	{
		perror("Error ");
		exit(1);
	}

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	push(60);

	N = pop();
	printf("N : %d \n", N); //60

	printf("%d \n", pop()); //50
	printf("%d \n", pop()); //40
	printf("%d \n", pop()); //30
	printf("%d \n", pop()); //20
	printf("%d \n", pop()); //10

	printf("%d \n", pop()); //empty

	return 0;
}