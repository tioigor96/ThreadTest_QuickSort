PROG_NAME = Thread_QuickSort
CC = gcc 
CFLAGS = -std=c11
LIBS = -pthread
OBJECTS = obj/main.o obj/QuickSort.o obj/benchmark.o obj/dynstack.o obj/utils.o
MKDR = mkdir

all: $(PROG_NAME)

$(PROG_NAME): obj $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(CFLAGS) $(LIBS)
	
obj:
	$(MKDR) $@

obj/main.o: main.c libs/QuickSort.h libs/benchmark.h libs/dynstack.h libs/utils.h
	$(CC) -c main.c -o $@ $(CFLAGS) $(LIBS)

obj/QuickSort.o: libs/QuickSort.h src/QuickSort.c libs/utils.h libs/dynstack.h
	$(CC) -c src/QuickSort.c -o $@ $(CFLAGS)

obj/benchmark.o: libs/benchmark.h src/benchmark.c
	$(CC) -c src/benchmark.c -o $@ -D_POSIX_C_SOURCE=199309L $(CFLAGS)

obj/dynstack.o: libs/dynstack.h src/dynstack.c
	$(CC) -c src/dynstack.c -o $@ $(CFLAGS)

obj/utils.o: libs/utils.h src/utils.c
	$(CC) -c src/utils.c -o $@ $(CFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -rf obj
	rm -f $(PROG_NAME)
