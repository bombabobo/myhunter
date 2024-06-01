##
## EPITECH PROJECT, 2023
## delivery
## File description:
## Makefile
##

LIBRARY_NAME = libmy.a
HEADER_NAME = my.h

build:
	gcc -c *.c
	ar rcs $(LIBRARY_NAME) *.o
	cp $(LIBRARY_NAME) ../$(LIBRARY_NAME)
	mkdir -p ../../include
	cp $(HEADER_NAME) ../../include/$(HEADER_NAME)
	make clean

clean :
	find -type f -iname "*.o" -delete

fclean : clean
	rm -f $(LIBRARY_NAME) ../$(LIBRARY_NAME)
