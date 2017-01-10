NAME = libft.a

SRCFILES = ft_isascii.c ft_lstadd.c ft_bzero.c ft_lst_rot.c ft_lstdel.c ft_lstcpy.c ft_strtrim.c ft_lstdelone.c ft_strsub.c ft_lst_strsplit.c ft_lstevenelem.c ft_strlen.c ft_strsplit.c ft_lstlastelem.c ft_lstlen.c ft_lstprint.c ft_lstpush_back.c ft_lsttotaldel.c ft_memalloc.c ft_memdel.c ft_memset.c ft_nearest_sqr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_putchar.c ft_putchar_fd.c

OFILES = $(SRCFILES:.c=.o)

INCL = -I../include

FLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCFILES) ft
	gcc $(FLAGS) -c $(SRCFILES) $(INCL)
	ar rc $(NAME) $(OFILES)
ft: libft
	$(MAKE) -C libft
all: $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
