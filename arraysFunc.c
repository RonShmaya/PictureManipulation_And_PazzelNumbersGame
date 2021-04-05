#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "arraysFunc.h"


void 	InitRandomIntToArray(int* p,int size,int maxRand,int minRand)
{
	srand(time(NULL)); 
	
	for(int i=0; i<size; i++, p++)
	{
		*p=minRand+(rand()%(maxRand-minRand+1)); 
		
	}
	

}
void PrintMatrix(const int* p,int rows,int cols)
{
	for(int i=0; i<rows; i++)
	{
		PrintArray((p+cols*i),cols);	
	}
}
void PrintArray(const int* p,int size) 
{
	for(int i=0; i<size; i++, p++)
	{
		printf("%5d",*p);
	
	}
	printf("\n");
}
void 	MoveInCircleMat(int* top,int* right,int* down,int* left)
{
	int temp1,temp2;
	temp1=*right;
	*right=*top;
	temp2=*down;
	*down=temp1;
	*top=*left;
	*left=temp2;

}
void	InitArrayFromOneToEnd(int* p,int size)
{
	for(int i=0;i<size; i++,p++)
	{
		*p=(i+1);
	}
}
int 	ChekIfMatValuesGoUp(const int* p,int size) 
{
	for(int i=0; i<size-2; i++)
	{
		if(*(p+i) >= *(p+i+1))
			return 0;
		
	}
	if(*(p+size-1)==0)
		return 1;
		
	return 0;

}
