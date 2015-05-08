CC=g++
NAME=./bin/DDOS
SRC=./src/DDOS.cc ./src/commands.cc
OBJ= $(SRC:%.cc=%.o)
RM=rm -f
FOLDER=./src/

all: $(NAME)

$(NAME): $(OBJ)
				$(CC) -o $(NAME) $^

$(OBJ):
				$(CC) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
