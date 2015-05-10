CC=g++
NAME=./bin/DDOS
SRC=./src/DDOS.cc ./src/commands.cc
OBJ= $(SRC:%.cc=%.o)
RM=rm -f
FOLDER=./src/
FLAGS=-std=c++11

all: $(NAME)

$(NAME): $(OBJ)
				$(CC) -o $(NAME) $^ $(FLAGS)

$(OBJ):
				$(CC) -o $@ -c $< $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
