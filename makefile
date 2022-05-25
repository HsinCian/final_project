a.out: main.o insert.o sort_pointer_array.o 
	gcc -o a.out main.o insert.o sort_pointer_array.o
main.o: main.c insert.h sort_pointer_array.h struct.h
	gcc -c main.c
insert.o: insert.c insert.h struct.h
	gcc -c insert.c
sort_pointer_array.o: sort_pointer_array.c sort_pointer_array.h struct.h
	gcc -c sort_pointer_array.c
