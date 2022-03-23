#include <vld.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y,i,j;
	int **ptr;

	printf("\n행,열입력? ");
	scanf("%d%d",&x, &y);

	ptr=(int **)malloc(sizeof(int*)*x);

	for(i=0;i<x;i++)
		ptr[i]=(int*)malloc(sizeof(int)*y);

   for(i=0;i<x;i++)
   {
   	  for(j=0;j<y;j++)
   	  {
   		 printf("%d행, %d열 값? ", i, j);
   		 scanf("%d", &ptr[i][j]);
      }
   }

   printf("\n입력된 행열의 값 \n");
   for(i=0;i<x;i++)
   {
   	 for(j=0;j<y;j++)
   		printf("%3d ,", *(*(ptr+i)+j));
      printf("\n");
   }

   /*for (i = 0; i<x; i++)
   	 free(ptr[i]);
   free(ptr);
   */
   //ptr=NULL;

   return 0;
}

funcA()
{
    printf("funcA() called. \n");
}