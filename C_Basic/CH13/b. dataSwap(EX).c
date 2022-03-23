#include <stdio.h>


swap(void* sour, void* dest, int size); //두개의 void 형 선언과 사이즈 선언 


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
//일반화 함수(Generic function) : 자료형에 구애받지 않고 하나의 로직으로 다양한 데이터를 처리하는 기술 
swap(void* sour, void* dest, int size) //두개의 void 형 선언과 사이즈 선언 
{
	char tmp, i;

	for (i=0; i<size;i++)
	{ 	tmp = *((char*)sour+i); // 500으로간 1바이트 -> x1,  i=0 번지 부터 시작  
	*((char*)sour + i) = *((char*)dest +i); // y1이 소스 1바이트 x1-> x2 
	*((char*)dest + i) = tmp;
	}
}