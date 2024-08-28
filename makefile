WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = 

SRCS = a1.c
OBJS = $(SRCS:%.c=%.o)

a1: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o a1

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1

test1: a1

clean: # remove all machine generated files
	rm -f a1 *.o output? *~