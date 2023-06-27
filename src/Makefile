OBJS = main.o history.o tokenizer.o
CFLAGS = -g -O3 -Wall -Wextra

all: main

main: $(OBJS)
	cc -o main $(CFLAGS) $(OBJS)

main.o: main.c history.h tokenizer.h
	cc -c $(CFLAGS) main.c

history.o: history.c history.h
	cc -c $(CFLAGS) history.c

tokenizer.o: tokenizer.c tokenizer.h
	cc -c $(CFLAGS) tokenizer.c

clean:
	rm -f *.o tokenizer main history

run: main
	./main
