CC?=gcc
CFLAGS=-Wall -std=c99

default: linked_list_test

linked_list_test: *.c *.h
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/linked_list_test linked_list_test.c linked_list.c

test: linked_list_test
	./bin/linked_list_test

profile: linked_list_test
	valgrind bin/linked_list_test

clean:
	rm -f *.o
	rm -rf bin
