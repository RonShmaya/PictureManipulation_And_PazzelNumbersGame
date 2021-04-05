CC=gcc
OBJS= main.o numberGame.o pictureManipulation.o arraysFunc.o
EXEC= prog1
DEBUG= -g
CFLAG= -std=c99 -Wall -Werror $(DEBUG)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@
	
arrays.o: arraysFunc.c arraysFunc.h
main.o: main.c pictureManipulation.h numberGame.h
numberGame.o: numberGame.c numberGame.h arraysFunc.h
pictureManipulation.o: pictureManipulation.c pictureManipulation.h arraysFunc.h


clean:
	rm -f $(OBJS) $(EXEC)
	
	
