# Compiler
CC = gcc

#Compiler Flags
CFLAGS=-Wall -std=c99 -g 

#Sources
SOURCES = Nav.c Mem.c read_write.c

#Objects
OBJECTS = Nav.o Mem.o read_write.o


navigate: $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $(OBJECTS)

Mem.o: Mem.c Navheader.h
Nav.o: Nav.c Navheader.h
read_write.o: read_write.c Navheader.h

clean::
		rm -f *.o core a.out navigate*~

depend::
		makedepend $(SOURCES)

test:
	 @for t in $(wildcard Girinos01/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Girinos02/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Crisalidas01/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Crisalidas02/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Minhocas01/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Minhocas02/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Aranhicos01/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done

	@for t in $(wildcard Tarantulas/*.maps); do \
		 time ./navigate $$t; \
		echo ./navigate $$t; \
	done



checker:
	@for t in $(wildcard Girinos01/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Girinos02/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Crisalidas01/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Crisalidas02/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Minhocas01/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done 

	@for t in $(wildcard Minhocas02/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Aranhicos01/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done

	@for t in $(wildcard Tarantulas/*.maps); do \
		./navigateChecker $$t; \
		echo ./navigateChecker $$t; \
	done


