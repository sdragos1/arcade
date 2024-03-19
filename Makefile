##
## EPITECH PROJECT, 2024
## arcade [WSL: Ubuntu-22.04]
## File description:
## Makefile
##

NAME = 				arcade
BUILD_PATH = 		build

all:
	@cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILD_PATH)

clean:
	@rm -rf $(BUILD_PATH)
	rm -rf lib

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	echo "pass"

update_module:
	@git submodule init
	@git submodule update

.PHONY: all clean fclean re tests_run
DEFAULT_GOAL := all
