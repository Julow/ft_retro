# LOL

NAME = ft_retro

all: $(NAME)

o/main.cpp.o: srcs/main.cpp o/ h/ft_retro.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

MSG_0 = '\r\033[0;32m%-13.13s\033[0;0m\r'
MSG_1 = '\r\033[0;31m%-13.13s\033[0;0m\n'

$(NAME): o/main.cpp.o
	@printf $(MSG_0) $@
	@clang++ -Wall -Wextra -Werror -O2 -o $@  o/main.cpp.o -lncurse && echo || printf $(MSG_1) $@

o/:
	@mkdir -p $@ 2> /dev/null || true

o/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f o/main.cpp.o 2> /dev/null || true
	@rmdir -p o 2> /dev/null || true

fclean: clean
	@rm -f ft_retro 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re make
