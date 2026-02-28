CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror -g -O0 
LDFLAGS = -fsanitize=address

all:
	$(CC) $(CFLAGS) main.c -o app 

sanitize:
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o app $(LDFLAGS)
