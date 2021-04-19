default: build debug

exec: build run

build:
	gcc -g main.c sorter.c file_lib.o

run:
	./a.out out_of_order_file tmp.txt

debug:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out out_of_order_file tmp.txt
