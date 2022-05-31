a.out: main.o insert.o sort_pointer_array.o myIO.o distance.o random.o my_habit.o
	gcc -o a.out main.o insert.o sort_pointer_array.o myIO.o -lm distance.o random.o -lm my_habit.o
myIO.o: myIO.c myIO.h struct.h
	gcc -c myIO.c
main.o: main.c insert.h sort_pointer_array.h random.h my_habit.h struct.h myIO.h
	gcc -c main.c
insert.o: insert.c insert.h struct.h myIO.h
	gcc -c insert.c
sort_pointer_array.o: sort_pointer_array.c sort_pointer_array.h struct.h
	gcc -c sort_pointer_array.c
distance.o: distance.c distance.h struct.h myIO.h
	gcc -c distance.c
random.o: random.c random.h distance.h struct.h myIO.h
	gcc -c random.c
my_habit.o: my_habit.c my_habit.h struct.h myIO.h
	gcc -c my_habit.c
all:
	python3 pic.py button.py insert.py delete.py search.py print.py type.py distance.py ran.py map_button.py locate.py
