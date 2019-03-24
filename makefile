objects = main.o sort.o

edit : $(objects)
	cc -o edit $(objects)

main.o : main.c sort.h
	cc -c main.c sort.h
sort.o : sort.c
	cc -c sort.c
.PHONY : clean
clean:
	-rm sort.o main.o
	-rm sort.h.gch edit
