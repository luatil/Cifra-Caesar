main.o: main.c
	gcc -Wall -Werror -g -o main main.c

clean: 
	rm *.o
