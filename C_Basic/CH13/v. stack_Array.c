#include <stdio.h>

#define STACK_SZ 5

int top = -1;
int stack[STACK_SZ];

push(int value)
{
	if (top >= STACK_SZ - 1) // 정해진 메모리 크기에 저장된 stack
	{
		printf("Stack full !!! \n");
		return;
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

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	N = pop();
	printf("N : %d \n", N); //50

	printf("%d \n", pop()); //40
	printf("%d \n", pop()); //30
	printf("%d \n", pop()); //20
	printf("%d \n", pop()); //10

	printf("%d \n", pop()); //empty

	return 0;
}