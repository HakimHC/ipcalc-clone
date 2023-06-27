# name of the binary
NAME 	= myipcalc

# compiler
CC 	= gcc

# compiler flags
CFLAGS 	= -Wall -Wextra -Werror

CFLAGS += -I $(INC)

CFLAGS += -I $(LIBDIR)/inc

CFLAGS += -g3

# directory of header files
INC 	= include

# linker flags
LDFLAGS = -fsanitize=address

LDFLAGS += -L./libft -lft

LDFLAGS += -lm

#libft

LIBDIR 	= libft

LIB 	= libft.a

LIBFT 	= $(addprefix $(LIBDIR)/,$(LIB))

# source files

SRCDIR 	= src

SRCFILE = main.c \
	  parser.c \
	  get_values.c \
	  errors.c

SRC 	= $(addprefix $(SRCDIR)/,$(SRCFILE))

# compiled object files
OBJ 	= $(SRC:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	make fclean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
