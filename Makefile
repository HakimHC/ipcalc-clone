# name of the binary
NAME 	= myipcalc

# compiler
CC 	= gcc

# compiler flags
CFLAGS 	= -Wall -Wextra -Werror

CFLAGS += -I $(INC)

CFLAGS += -g3

# directory of header files
INC 	= include

# linker flags
LDFLAGS = -fsanitize=address

# source files

SRCDIR 	= src

SRCFILE = main.c \
	  parser.c

SRC 	= $(addprefix $(SRCDIR)/,$(SRCFILE))

# compiled object files
OBJ 	= $(SRC:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
