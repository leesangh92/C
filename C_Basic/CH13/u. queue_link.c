#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
	int id;
	char name[20];
	struct _node *next;
} node;

node *front, *rear; // 전역 변수

void init_queue(void);
int put(void);
void queue_print(void);
void get(void);
void clear_queue(void);

int main()
{
	int stop =1;
	char ch;

	init_queue();

	while(stop)
	{
		printf("\n==================\n");
		printf("1. Queue put .. \n");
		printf("2. Queue print.. \n");
		printf("3. Queue get .. \n");
		printf("4. Queue Clear .. \n");
		printf("5. Quit .. \n");
		printf("==================\n");
		printf("     select ... ? \n");
		printf("==================\n");

		ch=getchar();
		fflush(stdin);

		switch(ch)
		{
		case '1' : put();
			break;
		case '2' : queue_print();
			break;
		case '3' : get();
			break;
		case '4' : clear_queue();
			break;
		case '5' : stop=0;
		}
	}

	return 0;
}

void init_queue(void)
{
	front=rear=NULL;
}

int put(void)
{
	node *temp;

	while(1)
	{
		if ((temp = (node*)malloc(sizeof(node))) == NULL)
		{
			printf("memory allocation error... \n");

			return -1;
		}

		printf("ID ? (quit:-1) ");
		scanf("%d%*c", &temp->id);
		fflush(stdin);
		if(temp->id==-1)
			break;
		printf("NAME ? ");
		gets(temp->name);
		temp->next = NULL;

		if (rear == NULL)  // first node 
		{
			rear = temp;
			front = temp;
		}
		else
		{ 
			rear->next = temp;
			rear = temp;
 		}
	}

	free(temp);

   return 1;
}


void queue_print(void)
{
	node *temp;

    temp=front;
    printf("\nQueue list : front -> rear\n");

	while(temp)
	{
		printf("%-6d, %s \n", temp->id, temp->name);
		temp = temp->next;
    }
}

void get(void)
{
	node *x;

	if (front == NULL)  /* if empty */
	{
		printf("Queue underflow... \n");
		return ;
    }	
	 
    printf("\nGet node-> id:%d, name:%s \n", front->id, front->name);

	x = front;
	front = front->next;

    free(x);
     
	if(front==NULL)
		rear=NULL;
}

void clear_queue(void)
{
	node *x;

    while (front)
    {
		x = front;
 	    front = front->next;

	    free(x);
	 }

	 rear=NULL;
}
