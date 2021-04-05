#ifndef __ARRAYS__
#define __ARRAYS__


void 	InitRandomIntToArray(int* p,int size,int maxRand,int minRand); // same method for matrix and array
void 	PrintMatrix(const int* p,int rows,int cols);
void	 PrintArray(const int* p,int size);
void 	MoveInCircleMat(int* top,int* right,int* down,int* left); // can choose the diraction 

void	InitArrayFromOneToEnd(int* p,int size);
int 	ChekIfMatValuesGoUp(const int* p,int size);
#endif
