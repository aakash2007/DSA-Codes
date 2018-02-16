compileAll : test1.o driver.o
	gcc test1.o driver.o -o run

test1.o : test1.c test1.h
	gcc -c test1.c

driver.o : driver.c test1.c test1.h
	gcc -c driver.c