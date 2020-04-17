.PHONY = debug retest re

SRC =   src/borwein.cpp		\

MAIN =  main.cpp

OBJ =   $(SRC:.cpp=.o)

MAIN_OBJ =  $(MAIN:.cpp=.o)


CXXFLAGS = -Iinclude/ -fdiagnostics-color \

NAME =  110borwein

TEST =  110borwein.t

DEBUG = 110borwein.d

all: $(NAME)

make_lib:
	@echo ' ___  ___  ___                         _  _        _  _  _         ___  ___  ___'
	@echo '|___||___||___|  ___  ___  _ _ _  ___ <_>| | ___  | |<_>| |_  ___ |___||___||___|'
	@echo ' ___  ___  ___  / |  / . \|     || . \| || |/ ._> | || || . \<_-<  ___  ___  ___'
	@echo '|___||___||___| \_|_.\___/|_|_|_||  _/|_||_|\___. |_||_||___//__/ |___||___||___|'
	@echo '                                 |_|'

$(NAME): make_lib $(OBJ) $(MAIN_OBJ)
	@echo ' ___  ___  ___                         _  _                                              ___  ___  ___'
	@echo '|___||___||___|  ___  ___  _ _ _  ___ <_>| | ___   ___  _ _  ___  ___  _ _  ___  _ _ _  |___||___||___|'
	@echo ' ___  ___  ___  / |  / . \|     || . \| || |/ ._> | . \|  _>/ . \/ . ||  _><_> ||     |  ___  ___  ___'
	@echo '|___||___||___| \_|_.\___/|_|_|_||  _/|_||_|\___. |  _/|_|  \___/\_. ||_|  <___||_|_|_| |___||___||___|'
	@echo '                                 |_|              |_|            <___|'
	g++ -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CXXFLAGS)

debug: make_lib $(OBJ) $(MAIN_OBJ)
	g++ -g3 -o $(DEBUG) $(MAIN_OBJ) $(OBJ) $(CXXFLAGS)

tests_run: make_lib
	g++ -o $(TEST) $(OBJ) $(CXXFLAGS)
	./$(TEST)

retest: fclean tests_run

clean:
	@echo ' ___  ___  ___        _                  ___  ___  ___'
	@echo '|___||___||___|  ___ | | ___  ___  _ _  |___||___||___|'
	@echo ' ___  ___  ___  / |  | |/ ._><_> ||   |  ___  ___  ___'
	@echo '|___||___||___| \_|_.|_|\___.<___||_|_| |___||___||___|'
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: clean
	@echo ' ___  ___  ___   ___      _                  ___  ___  ___'
	@echo '|___||___||___| | |  ___ | | ___  ___  _ _  |___||___||___|'
	@echo ' ___  ___  ___  | |-/ |  | |/ ._><_> ||   |  ___  ___  ___'
	@echo '|___||___||___| |_| \_|_.|_|\___.<___||_|_| |___||___||___|'
	rm -f $(TEST) $(NAME)

re: fclean all
