CC=g++
NAME=./bin/DDOS
SRC=./src/DDOS.cc ./src/commands.cc
OBJ= $(SRC:%.cc=%.o)
RM=rm -f
FOLDER=./src/
FLAGS=-std=c++11

all: $(NAME)

$(NAME): $(OBJ)
				$(CC) -o $@ $^ $(FLAGS)

$(OBJ):
				$(CC) -o ./src/DDOS.o -c ./src/DDOS.cc $(FLAGS)
				$(CC) -o ./src/commands.o -c ./src/commands.cc $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all
