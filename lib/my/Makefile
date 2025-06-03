##
## EPITECH PROJECT, 2024
## my_ls
## File description:
## The Makefile
##

NAME		:=	../libmy.a

MY_SRCS		= \
	my_putchar.c \
	my_has_char.c \
	my_putstr.c \
	my_putnbr.c \
	my_has_char.c \
	my_getdouble.c \
	my_calloc.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strlen.c \
	my_strarraycpy.c \
	my_strdup.c \
	free_array.c \
	my_putstrarray.c \
	my_strncmp.c \
	my_split_str.c \
	my_bwrite.c \
	my_strarraylen.c

SRCS		= \
	$(addprefix src/, $(MY_SRCS))

OBJS		:=	$(SRC:.c=.o)

CFLAGS		:=	-iquote ./include/ -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

debug:	CFLAGS += -fsanitize=address -static-libasan -g3
debug:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
