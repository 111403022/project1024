try: stage1.o
	cc stage1.o -o try
stage1.o: stage1.c
	cc -Wall -c stage1.c
