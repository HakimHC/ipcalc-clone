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

# static library for testing

ARFLAGS = rcs

# source files

SRCDIR 	= src

SRCFILE = parser.c \
	  get_values.c \
	  errors.c \
	  print.c \
	  utils.c

SRC 	= $(addprefix $(SRCDIR)/,$(SRCFILE)) \

# compiled object files
OBJ 	= $(SRC:.c=.o)

MAIN 	= main.c

MAINSRC = $(addprefix $(SRCDIR)/,$(MAIN))

MAINOBJ = $(MAINSRC:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MAINOBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -sC libft

test: $(OBJ)
	$(AR) $(ARFLAGS) test.a $(OBJ)

clean:
	make fclean -C libft
	$(RM) $(OBJ)
	$(RM) test.a

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
