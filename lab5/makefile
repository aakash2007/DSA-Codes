# compileAll : compRecMS.o compIterMS.o runRecMS.o runIterMS.o
# 	gcc compRecMS.o compIterMS.o runRecMS.o runIterMS.o -o runAll

# compRecMS.o : compRecMS.c compRecMS.h
# 	gcc -c compRecMS.c

# compIterMS.o : compIterMS.c compIterMS.h
# 	gcc -c compIterMS.c

# runRecMS.o : runRecMS.c compRecMS.c compRecMS.h
# 	gcc -c runRecMS.c

compileAll : compRecMS.o runRecMS.o
	gcc compRecMS.o runRecMS.o -o runAll

compRecMS.o : compRecMS.c compRecMS.h
	gcc -c compRecMS.c

runRecMS.o : runRecMS.c compRecMS.c compRecMS.h
	gcc -c runRecMS.c