try: file.o queue.o
	cc file.o queue.o -o try
file.o: file.c queue.h
	cc -Wall -c file.c
queue.o: queue.c queue.h
	cc -Wall -c queue.c
