# Объявление переменных
CC = g++
CFLAGS =

# Правило для сборки программы
myprogram: main.o file_search.o
	$(CC) $(CFLAGS) -o myprogram main.o file_search.o

# Правило для компиляции main.cpp в объектный файл main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

file_search.o: file_search.c
	$(CC) $(CFLAGS) -c file_search.c

# Правило для очистки временных файлов
clean:
	rm -f *.o myprogram