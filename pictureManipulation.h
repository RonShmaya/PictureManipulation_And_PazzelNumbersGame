#ifndef P_M
#define P_M

#define SIZE_R_AND_C 5

#define USERPICK_WITHCLOCK 1 
#define USERPICK_AGAINSTCLOCK 2

#define RANDOM_MAX 99 //picture random init -> between 10-99
#define RANDOM_Min 10

void	 PictureManipulation();
void	 StartMatrix(int* mat,int size);
void	 MenuPM(); 				//user messeages
void 	MoveWithClock(int* p,int rows,int cols);
void	MoveAgainstClock(int* p,int rows,int cols);
void 	MoveMatLikeUserWant(int* p,int rows,int cols,int userPick); // function that know move with and against clock
void 	MoveHorizontal(int* p,int rows,int cols);
void 	MoveVertical(int* p,int rows,int cols);

//in pictureManipulation my solution with while and for loops (for training) may be for more fit 

#endif
