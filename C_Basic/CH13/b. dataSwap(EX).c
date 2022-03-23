#include <stdio.h>


swap(void* sour, void* dest, int size); //�ΰ��� void �� ����� ������ ���� 


int main()
{
	short int x1 = 100, x2 = 200;
	int y1 = 300, y2 = 500;
	double d1 = 1.6, d2 = 7.9;
	char names[2][20] = { "kim", "lee" };

	swap(&x1, &x2, sizeof(x1));
	swap(&y1, &y2, sizeof(int));
	swap(&d1, &d2, sizeof(double));
	swap(names[0], names[1], sizeof(names[0]));

	printf("x1 : %hd, x2:%hd\n", x1, x2);
	printf("y1 : %d, y2:%d\n", y1, y2);
	printf("d1 : %lf, x2:%lf\n", d1, d2);
	printf("names[0] : %s , names [1]:%s\n", names[0], names[1]);

	return 0;
}
//�Ϲ�ȭ �Լ�(Generic function) : �ڷ����� ���ֹ��� �ʰ� �ϳ��� �������� �پ��� �����͸� ó���ϴ� ��� 
swap(void* sour, void* dest, int size) //�ΰ��� void �� ����� ������ ���� 
{
	char tmp, i;

	for (i=0; i<size;i++)
	{ 	tmp = *((char*)sour+i); // 500���ΰ� 1����Ʈ -> x1,  i=0 ���� ���� ����  
	*((char*)sour + i) = *((char*)dest +i); // y1�� �ҽ� 1����Ʈ x1-> x2 
	*((char*)dest + i) = tmp;
	}
}