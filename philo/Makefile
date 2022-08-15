NAME	=	philo

SRCS	=	srcs/main.c \
			srcs/utils.c \
			srcs/parsing.c \
			srcs/init.c \
			srcs/start.c \

FLAGS	=	-I ./includes  

CC		=	gcc $(FLAGS)

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) -lpthread -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

