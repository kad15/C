# définition des cibles particulières
.PHONY: clean

# désactivation des règles implicites
#.SUFFIXES:

CC= gcc # compilateur

EXEC = ctp6_1main # nom du fichier binaire final

CFLAGS = -g -W -Wall


# all conditionnel
all : $(EXEC)

# liste des fichiers .c nécessaires au projet
sources = ctp6_1main.c ctp6_1.c


# nommage automatique des fichiers objets d'après les noms des sources C
objets = $(sources:.c=.o)

$(EXEC) : $(objets)
	$(CC) -o $@ $^ -lm

#Cette règle indique que chaque fichier .o nécessaire à la création du projet est obtenu à partir
#du fichier .c correspondant et que la commande $(CC) -o $@ -c $< permet de créer le
#fichier objet à partir du fichier source
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)



############################## fin makefile
#Signification :
# $@ : produit (ou but) de la règle
# $< : nom de la première dépendance (ou source)
# $? : toutes les dépendances plus récentes que le but
# $^ : toutes les dépendances
# Si on veut rajouter un fichier .c dans le projet, il suffit de le rajouter dans la liste des
# sources.

# clean
clean:
	rm -rf *.o rm -rf $(EXEC)
