CC = gcc
NAME = my_ls

SRC =			my_ls.c					\
				lib/my/my_putchar.c     \
                lib/my/my_putstr.c      \
                lib/my/my_strcmp.c

RM = rm-rf

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Werror -Wall -Wextra  

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: $(RM) -f $(OBJ)

fclean:			 clean
		$(RM) -f $(NAME)

re: fclean all
