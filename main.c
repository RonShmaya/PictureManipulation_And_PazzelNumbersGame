#include <stdio.h>
#include <ctype.h>
#include "pictureManipulation.h"
#include "numberGame.h"

int main()
{
	char ans;
	do
	{
		printf("\nPlease choose one of the following options\n");
		printf("P/p - Picture Manipulation\n");
		printf("N/n - Number Game\n");
		printf("E/e - Quit\n");
		do
		{
			scanf("%c",&ans);
			
		} while(isspace(ans));
		
		ans=toupper(ans);
		switch(ans)
		{
			case 'P':
				PictureManipulation();
			break;
			
			case 'N':
				NumberGame();
			break;
			
			case 'E':
				printf("Bye Bye\n");
			break;
			
			default:
				printf("input not ok please try again\n");
			break;
		}
	} while(ans!='E');

}


