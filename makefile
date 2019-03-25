objects = main.o sort.o

test : $(objects)
	cc -o test $(objects)

main.o : main.c sort.h
	cc -c main.c sort.h
sort.o : sort.c
	cc -c sort.c
.PHONY : clean
clean:
	-rm sort.o main.o test
	-rm sort.h.gch
