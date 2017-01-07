NAME = fillit

SCRFLDR = ./src

LIBFLDR = ./lib

INCFLDR = ./include

SCRFILES = alphabeterizer.c bisquick_mkii.c fits.c piece_trim.c place.c print_map.c reading.c solve.c unplace.c verif.c

OBJSCRFILES = $(SRCFILES:.c=.o)

OLDNAME = fillit.h.gch libft.h.gch

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L$(LIBFLDR)

LIBS = -lft

all: $(NAME)

$(NAME):
	cd $(LIBFLDR) && make && cd ..
	gcc $(FLAGS) -c $(SRCFILES) -I$(INCFLDR)
	gcc -o $(NAME) $(OBJSCRFILES) $(LFLAGS) $(LIBS)

clean:
	/bin/rm -f $(SRCFLDR) $(OBJSRCFILES)
	cd $(INCFLDR) && /bin/rm -f $(OLDNAME) && cd ..
	cd $(LIBFLDR) && make clean && cd ..

fclean: clean
	/bin/rm -f $(NAME)
	cd $(LIBFLDR) && make fclean && cd ..

re: fclean all

.PHONY: clean fclean re
