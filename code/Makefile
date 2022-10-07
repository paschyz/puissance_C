# define the compiler
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = -I/usr/local/include

# define library paths in addition to /usr/lib
#     if I wanted to include libraries not in /usr/lib I'd specify
#     their path using -Lpath, something like:
LFLAGS = -L/usr/local/lib

# define any libraries to link into executable:
#     if I wanted to include libraries not in /usr/lib I'd specify
#     their name using -lname, something like:
LIBS = -lm

# define the C source files
SRCS = main.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
# $(name:string1=string2)
#     For each word in 'name' replace 'string1' with 'string2'
OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = main

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o ../executables/$(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -f *.o *~ $(MAIN)	

run:
	../executables/$(MAIN)

help: 
	../executables/$(MAIN) -h

credits:
	../executables/$(MAIN) -c