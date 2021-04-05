#include <stdio.h>
#include "pictureManipulation.h"
#include "arraysFunc.h"


void	 PictureManipulation()
{	
	int mat[SIZE_R_AND_C][SIZE_R_AND_C];
	int sizeOfAllMat=sizeof(mat)/sizeof(mat[0][0]);
	StartMatrix((int*)mat,sizeOfAllMat);
	
	int userPick;
	do
	{
		MenuPM();
		scanf("%d",&userPick);
		switch(userPick)
		{
			case 1:
				MoveWithClock((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
				printf("\n\n--------- picture after manipulation ---------\n");
				PrintMatrix((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
			break;
			
			case 2:
				MoveAgainstClock((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
				printf("\n\n--------- picture after manipulation ---------\n");
				PrintMatrix((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
			break;
			
			case 3:
				MoveHorizontal((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
				printf("\n\n--------- picture after manipulation ---------\n");
				PrintMatrix((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
			break;
			
			case 4:
				MoveVertical((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
				printf("\n\n--------- picture after manipulation ---------\n");
				PrintMatrix((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
			break;
			case -1:
				
			break;
			
			default:
				printf("input not ok please try again\n");
			break;
		}
		
	}while(userPick!=-1);
}
void	 StartMatrix(int* mat,int size)
{
	InitRandomIntToArray(mat,size,RANDOM_MAX,RANDOM_Min); 
	PrintMatrix((int*)mat,SIZE_R_AND_C,SIZE_R_AND_C);
}

void	MenuPM()
{
		printf("\n\n");
		printf("Please choose one of the following options\n");
		printf("1 - 90 degree clockwise\n");
		printf("2 - 90 degree counter clockwise\n");
		printf("3 - Flip Horizontal\n");
		printf("4 - Flip Vertical\n");
		printf("-1 - Quit\n");
}
void 	MoveWithClock(int* p,int rows,int cols)
{
	MoveMatLikeUserWant(p,rows,cols,USERPICK_WITHCLOCK);
}
void MoveAgainstClock(int* p,int rows,int cols)
{
	MoveMatLikeUserWant(p,rows,cols,USERPICK_AGAINSTCLOCK);
}
void 	MoveMatLikeUserWant(int* p,int rows,int cols,int userPick) // work for two meth with and against clock
{
	int firstRow=0,firstCol=0; 
	int lastRow=rows-1,lastCol=cols-1; 
	int* remmemberaddress,*top,*right,*down,*left;
	int counter=0; //move on the right cell
	while(firstRow<lastRow && firstCol<lastCol)
	{
		while(counter<(lastCol-firstCol))
		{
			top=p+cols*firstRow+firstCol+counter;
			right=p+cols*(firstRow+counter)+lastCol;
			down=p+cols*lastRow+lastCol-counter;
			left=p+cols*(lastRow-counter)+firstCol;
			
			if(userPick==1)		//move with circle
				MoveInCircleMat(top,right,down,left);
				
			if(userPick==2)		//move against circle
				MoveInCircleMat(top,left,down,right);
			
			counter++;
		
		}
		counter=0;
		firstRow++;
		firstCol++;
		lastRow--;
		lastCol--;
	}
}
void MoveHorizontal(int* p,int rows,int cols)
{
	int temp;
	int *down,*up;
	for(int i=0; i<(rows/2); i++)
	{
		down=p+cols*(rows-1-i);
		up=p+cols*i;
		for(int j=0; j<cols; j++)
		{
			temp=*down;
			*down=*up;
			*up=temp;
			down=down+1;
			up=up+1;
			
		}
	}
}
void MoveVertical(int* p,int rows,int cols)
{
	int temp;
	int *right,*left;
	for(int i=0; i<(rows/2); i++)
	{	 
		for(int j=0; j<cols; j++)
		{
			left=p+cols*j+i;
			right=p+cols*j+cols-1-i;
			
			temp=*right;
			*right=*left;
			*left=temp;
		}
	}
}
