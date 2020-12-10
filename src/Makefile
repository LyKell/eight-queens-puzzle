# Auteurs : Kevin SAVANE et Tom REDON
# Creation : 26-03-2019
# Modification : 26-03-2019

# Definition des constantes
CC = gcc
CFLAGS = -ansi -Wall
EXEC = dames
LDFLAGS = -lMLV
OBJ = Main.o IGraph.o Pieces.o Echiquier.o

# Definition des commandes a effectuer
dames : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

Main.o : Main.c IGraph.o Pieces.h

Echiquier.o : Echiquier.c Echiquier.h

Pieces.o : Pieces.c Pieces.h Echiquier.h

IGraph.o : IGraph.c IGraph.h Echiquier.h Pieces.h


%.o : %.c
	$(CC) -c $< $(CFLAGS) $(LDFLAGS)


# Definition des commandes de nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f $(EXEC)


# Definition des commandes a appeler
install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
