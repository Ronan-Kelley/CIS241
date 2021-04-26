flags=-g -O0

default: execute

execute: build run

dbg: build debug

testsort:
	clang $(flags) test_sorter.c sorter.c -o b.out
	./b.out

build:
	clang $(flags) main.c sorter.c file_lib.o -o a.out

run:
	./a.out out_of_order_file tmp.txt

debug:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out out_of_order_file tmp.txt
