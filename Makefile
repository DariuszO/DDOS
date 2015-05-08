CC=g++
NAME=./bin/DDOS
SRC=./src/DDOS.cc ./src/commands.cc
OBJ= $(SRC:%.cc=%.o)
RM=rm -f
FOLDER=./src/

all: $(NAME)

$(NAME): $(FOLDER)DDOS.o $(FOLDER)commands.o
					$(CC) -o $(NAME) $^

	$(OBJ):
					$(CC) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
