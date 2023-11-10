FLAGS = -Wall -Werror -Wextra
CC = gcc

all: s21_cat

s21_cat: s21_cat.o arguments_parser.o flag_handlers.o
	$(CC) $(FLAGS) build/s21_cat.o build/arguments_parser.o build/flag_handlers.o -o build/s21_cat
	rm -rf build/*.o

s21_cat.o: src/s21_cat.c
	$(CC) $(FLAGS) -c src/s21_cat.c -o build/s21_cat.o

arguments_parser.o: src/arguments_parser.c
	$(CC) $(FLAGS) -c src/arguments_parser.c -o build/arguments_parser.o

flag_handlers.o: src/flag_handlers.c
	$(CC) $(FLAGS) -c src/flag_handlers.c -o build/flag_handlers.o
clean:
	rm -rf build/*.o build/s21_cat




