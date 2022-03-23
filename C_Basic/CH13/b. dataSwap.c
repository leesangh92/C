#include <stdio.h>

void swap(void* sour, void* dest, int size);

int main()
{
	short int x1 = 100, x2 = 200;
	int y1 = 300, y2 = 500;
	double d1 = 1.6, d2 = 7.9;
	char names[2][20] = { "kim", "lee" };

	//swap(x1, x2); // call by value�� ���μ��� ������ ���� ���Ѵ�.
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

// �Ϲ�ȭ �Լ�(generic function) : �ڷ����� ���ֹ��� �ʰ� �ϳ��� �������� �پ��� �����͸� ó���ϴ� ��
void swap(void *sour, void *dest, int size) // void �����ͷ� ���� �ڷ����� �μ��� �޾Ƶ��δ�.
{
	char tmp, i;

	for (i = 0; i < size; i++)
	{
		tmp = *((char*)sour + i);
		*((char*)sour + i) = *((char*)dest + i);
		*((char*)dest+i) = tmp;
	}
}

//swap(short int *sour, short int *dest) // call by reference, ���� ���� �ڷ����� ���� �̸��� ���� �Լ��� ����� �Ұ����ϴ�.
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