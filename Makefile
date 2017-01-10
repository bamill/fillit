NAME = fillit

SRCFILES = alphabeterizer.c piece_trim.c piece_y.c place.c print_map.c reading.c solve.c unplace.c verif.c fitter.c ft_stomultistr.c ft_lstlastelem.c ft_lstpush_back.c ft_nearest_sqr.c ft_lstevenelem.c\
ft_lsttotaldel.c blank_x.c

SRCFLDR = src

OFILES = $(SRCFILES:.c=.o)

INCL = -I./include

LIB = -L. $(LIBFLDR)/libft/libft.a

LIBFLDR = ./lib

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@make -C $(LIBFLDR)
	gcc -c $(FLAGS) $(addprefix $(SRCFLDR)/, $(SRCFILES)) $(INCL)
	gcc -o $(NAME) $(OFILES) $(INCL) $(LIB)
	mv $(OFILES) $(SRCFLDR)

all: $(NAME)

clean:
	@make -C $(LIBFLDR) clean
	/bin/rm -f $(addprefix $(SRCFLDR)/, $(OFILES))

fclean: clean
	@make -C $(LIBFLDR) fclean
	/bin/rm -f $(NAME)

re: fclean all
