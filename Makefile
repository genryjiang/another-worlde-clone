CC = clang
CFLAGS = -Wall -Werror -g

all: wordle

wordle: wordle.c game.c list.c dict.c 
	$(CC) $(CFLAGS) -o wordle game.c wordle.c list.c dict.c 

clean:
	rm -f wordle
