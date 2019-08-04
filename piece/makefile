source = $(filter-out winsock.c, $(wildcard *.c))
header = $(wildcard *.h)

#unit: unit.c algorithm.h algorithm.c
#	gcc unit.c algorithm.c -o unit -g

unit: $(source) $(header)
	gcc $^ -o unit -g
