#include <stdio.h>

void swap(void* sour, void* dest, int size);

int main()
{
	short int x1 = 100, x2 = 200;
	int y1 = 300, y2 = 500;
	double d1 = 1.6, d2 = 7.9;
	char names[2][20] = { "kim", "lee" };

	//swap(x1, x2); // call by value로 실인수에 영향을 주지 못한다.
	swap(&x1, &x2, sizeof(x1));
	swap(&y1, &y2, sizeof(int));
	swap(&d1, &d2, sizeof(double));
	swap(names[0], names[1], sizeof(names[0]));

	printf("x1 : %hd, x2 : %hd \n", x1, x2);
	printf("y1 : %d, y2 : %d \n", y1, y2);
	printf("d1 : %lf, d2 : %lf \n", d1, d2);
	printf("names[0] : %s, names[1] : %s \n", names[0], names[1]);

	return 0;
}

// 일반화 함수(generic function) : 자료형에 구애받지 않고 하나의 로직으로 다양한 데이터를 처리하는 것
void swap(void *sour, void *dest, int size) // void 포인터로 여러 자료형을 인수로 받아들인다.
{
	char tmp, i;

	for (i = 0; i < size; i++)
	{
		tmp = *((char*)sour + i);
		*((char*)sour + i) = *((char*)dest + i);
		*((char*)dest+i) = tmp;
	}
}

//swap(short int *sour, short int *dest) // call by reference, 여러 개의 자료형을 같은 이름의 여러 함수로 사용이 불가능하다.
//{
	//short int tmp;

	//tmp = *sour;
	//*sour = *dest;
	//*dest = tmp;
//}

//swap(swap(short int sour, short int dest) // call by value
//{
	//short int tmp;

	//tmp = sour;
	//sour = dest;
	//dest = tmp;
//}