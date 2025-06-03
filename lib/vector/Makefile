##
## EPITECH PROJECT, 2024
## my_ls
## File description:
## The Makefile
##

NAME		:=	../libvector.a

MY_SRCS		= \
	vector_create.c \
	vector_destroy.c \
	vector_push_back.c \
	vector_pop_back.c \
	vector_insert.c \
	vector_erase.c \
	vector_set.c \
	vector_size.c \
	vector_capacity.c \
	vector_resize.c \
	vector_reserve.c \
	vector_clear.c \
	vector_is_empty.c \
	vector_print.c \
	clear_n_bytes.c \
	copy_n_bytes.c \
	simple_free.c

SRCS		= \
	$(addprefix src/, $(MY_SRCS))

OBJS		:=	$(SRC:.c=.o)

CFLAGS	:=	-iquote ./include/ -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS) $(CPPFLAGS)

debug:	CFLAGS += -fsanitize=address -static-libasan -g3
debug:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
