##
## EPITECH PROJECT, 2024
## arcade [WSL: Ubuntu-22.04]
## File description:
## Makefile
##

NAME = 				arcade
BUILD_PATH = 		build

all:
	cmake -S . -B $(BUILD_PATH) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILD_PATH)

clean:
	@rm -rf $(BUILD_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: fclean
	cmake -S . -B $(BUILD_PATH) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILD_PATH)

tests_run: fclean
	cmake -S . -B $(BUILD_PATH) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON
	cmake --build $(BUILD_PATH)
	ctest --test-dir $(BUILD_PATH)

update_module:
	@git submodule init
	@git submodule update --remote --merge

style: fclean
	@cpplint --recursive src tests shared

.PHONY: all clean fclean re tests_run
DEFAULT_GOAL := all
