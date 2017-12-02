CC=gcc 
CFLAGS=-Wall -Werror

main.out: helper.o main.o
	$(CC) $(CFLAGS) -o main.out $^

clean:
	rm main.o main.out helper.o