##
## EPITECH PROJECT, 2024
## arcade [WSL: Ubuntu-22.04]
## File description:
## Makefile
##

NAME = 				arcade
BUILD_PATH = 		build

all:
					@cmake -S . -B build
					cmake --build $(BUILD_PATH)
					@cp $(BUILD_PATH)/$(NAME) .

clean:
					@rm -rf $(BUILD_PATH)

fclean:		clean
					@rm -f $(NAME)

re: 			fclean all

tests_run:
					echo "pass"

update_module:
					@git submodule init
					@git submodule update

.PHONY: all clean fclean re tests_run
DEFAULT_GOAL := all
