NAME = philo

SOURCES = philo.c \
		routine.c \
		utils.c \
		print.c


OBJECTS = $(SOURCES:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)

bonus: $(BONUS)
	$(AR) -r $(NAME) $?
	
clean:
		rm -f $(OBJECTS) $(BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test