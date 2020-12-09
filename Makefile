compile: gabrielSimoura.c arv.c
	gcc -ggdb -std=c99 -Wall -Werror -o main *.c

clean:
	rm -f *.o a.out core main

