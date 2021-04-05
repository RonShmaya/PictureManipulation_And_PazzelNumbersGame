#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "numberGame.h"
#include "arraysFunc.h"
void NumberGame()
{
	int mat[N][M];
	int sizeOfAllMat=sizeof(mat)/sizeof(mat[0][0]);
	int zeroRow,zeroCol;
	InitArrayFromOneToEnd((int*)mat,sizeOfAllMat); //common method init from 1 to arr.lenght()
	mat[N-1][M-1]=0; //last place = 0
	ShuffelMat((int*)mat,M,N,SHUFFEL_COUNT,&zeroRow,&zeroCol);
	StartGame((int*)mat,N,M,&zeroRow,&zeroCol);
	
	
}

void ShuffelMat(int* p,int cols,int rows,int numOfShuffel,int* zeroRowInEnd,int* zeroColInEnd)
{
	srand(time(NULL)); 
	int shuffelPick;
	
	int lastPlaceValueZero=*(p+cols*rows-1);
	if(lastPlaceValueZero!=0) // in start last place value = 0
		return;
		
	int zeroRow=rows-1 ,zeroCol=cols-1;
	int* zeroRowPointer=&zeroRow ,*zeroColsPointer=&zeroCol; //pointers go method and update where zero

	for(int i=0; i<numOfShuffel; i++)
	{
		shuffelPick=DOWN+(rand()%(UP-DOWN+1)); 	// between 0-3
		Replace(p,cols,rows,zeroRowPointer,zeroColsPointer,shuffelPick);
	}  
	*zeroRowInEnd=*zeroRowPointer;	//who call for this meth get where value now
	*zeroColInEnd=*zeroColsPointer;
}
void Replace(int *p,int cols,int rows,int* zeroRowP,int* zeroColsP,int pickMove)
{
	int zeroRow=*zeroRowP, zeroCol=*zeroColsP;
	switch(pickMove)
		{
			case UP: // zero go up
				if(zeroRow-1 >= 0)
				{
					*(p+cols*zeroRow+zeroCol)=*(p+cols*(zeroRow-1)+zeroCol);
					zeroRow--;
				}	
			break;
			case DOWN: // zero go down
				if(zeroRow+1 < rows)
				{
					*(p+cols*zeroRow+zeroCol)=*(p+cols*(zeroRow+1)+zeroCol);
					zeroRow++;
				}
			break;
			case RIGHT: // zero go right
				if(zeroCol+1 < cols)
				{
					*(p+cols*zeroRow+zeroCol)=*(p+cols*zeroRow+zeroCol+1);
					zeroCol++;
				}
				
			break;
			case LEFT: // zero go left
				if(zeroCol-1 >= 0)
				{
					*(p+cols*zeroRow+zeroCol)=*(p+cols*zeroRow+zeroCol-1);
					zeroCol--;
				}
			break;
		}
		*(p+cols*zeroRow+zeroCol)=0; // move 0 in new place
		*zeroRowP=zeroRow; 	      // update zero place
		*zeroColsP=zeroCol;
}
void StartGame(int *p,int rows,int cols,int* zeroRowP,int* zeroColP)
{
	printf("\n\n");
	PrintMatrix(p,rows,cols);
	printf("\n\n");
	int size=rows*cols;
	int isFinish=ChekIfMatValuesGoUp(p,size);
	int userPick;
	while(isFinish==0)
	{
		printf("Your step: ");
		scanf("%d",&userPick);
		int isChange=TryToChange(p,rows,cols,zeroRowP,zeroColP,userPick);
		if(isChange==1)
		{
			printf("\n\n");
			PrintMatrix(p,rows,cols);
			printf("\n\n");
			isFinish=ChekIfMatValuesGoUp(p,size);
			
		}
		else
			printf("Invalid Step!\n");
	}
	printf("\nYou win! The game is over! \n\n");
	
}
int	TryToChange(int *p,int rows,int cols,int* zeroRowP,int* zeroColP,int userPick)
{
	if(userPick>(rows*cols-1))
	return 0;
	int zeroRow=*zeroRowP,zeroCol=*zeroColP;
	if(zeroRow-1 >= 0 && userPick==*(p+cols*(zeroRow-1)+zeroCol))
	{
		Replace(p,cols,rows,zeroRowP,zeroColP,UP); //try to replace and update pointer
	}
	else if(zeroRow+1 < rows && userPick==*(p+cols*(zeroRow+1)+zeroCol))
	{
		Replace(p,cols,rows,zeroRowP,zeroColP,DOWN);
	}
	else if(zeroCol+1 < cols && userPick==*(p+cols*zeroRow+zeroCol+1))
	{
		Replace(p,cols,rows,zeroRowP,zeroColP,RIGHT);
	}
	else if(zeroCol-1 >= 0 && userPick==*(p+cols*zeroRow+zeroCol-1))
	{
		Replace(p,cols,rows,zeroRowP,zeroColP,LEFT);
	}
	else
		return 0;
		
	return 1;
}




