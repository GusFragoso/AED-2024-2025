# Compiler
CC = gcc


#Compiler Flags
CFLAGS=-Wall -std=c99 -g

#Sources
SOURCES = Nav.c Func.c Mem.c read_write.c

#Objects
OBJECTS = Nav.o Func.o Mem.o read_write.o


navigate: $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $(OBJECTS)

Mem.o: Mem.c Navheader.h
Func.o: Func.c Navheader.h
Nav.o: Nav.c Navheader.h
read_write.o: read_write.c Navheader.h

clean::
		rm -f *.o core a.out navigate*~

depend::
		makedepend $(SOURCES)
#DO NOT DELETE