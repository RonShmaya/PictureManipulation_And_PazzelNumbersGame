#ifndef __NUMBER__GAME__
#define __NUMBER__GAME__

#define M 4
#define N 5

#define SHUFFEL_COUNT 10
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

void 	NumberGame();
void	ShuffelMat(int* p,int cols,int rows,int numOfShuffel,int* zeroRowInEnd,int* zeroColInEnd);

	//replace values,update pointer where value now 
void	Replace(int *p,int cols,int rows,int* zeroRowP,int* zeroColsP,int shuffelPick); 
 
void	StartGame(int *p,int rows,int cols,int* zeroRowP,int* zeroColP);

	//try to change user pick with zero
int	TryToChange(int *p,int rows,int cols,int* zeroRowP,int* zeroColP,int userPick);

#endif
