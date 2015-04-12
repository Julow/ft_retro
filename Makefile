# LOL

NAME = ft_retro

all: $(NAME)

o/AEntity.cpp.o: srcs/AEntity.cpp h/AEntity.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/colors.cpp.o: srcs/colors.cpp h/ft_retro.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/EnnemiEntity.cpp.o: srcs/EnnemiEntity.cpp h/EnnemiEntity.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/EntityArray.cpp.o: srcs/EntityArray.cpp h/EntityArray.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/Game.cpp.o: srcs/Game.cpp h/Game.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/HitBox.cpp.o: srcs/HitBox.cpp h/HitBox.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/main.cpp.o: srcs/main.cpp h/ft_retro.hpp h/Game.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/PlayerEntity.cpp.o: srcs/PlayerEntity.cpp h/PlayerEntity.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/Projectile.cpp.o: srcs/Projectile.cpp h/Projectile.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

o/Weapon.cpp.o: srcs/Weapon.cpp h/Weapon.hpp h/Game.hpp
	@printf $(MSG_0) $<
	@clang++ -Wall -Wextra -Werror -O2 -Ih  -c -o $@ $< || printf $(MSG_1) $<

MSG_0 = '\\033[0;32m%-21.21s\\033[0;0m\\r'
MSG_1 = '\\033[0;31m%-21.21s\\033[0;0m\\n'

$(NAME): o/ o/ o/ o/ o/ o/ o/ o/ o/ o/ o/AEntity.cpp.o o/colors.cpp.o o/EnnemiEntity.cpp.o o/EntityArray.cpp.o o/Game.cpp.o o/HitBox.cpp.o o/main.cpp.o o/PlayerEntity.cpp.o o/Projectile.cpp.o o/Weapon.cpp.o
	@printf $(MSG_0) $@
	@clang++ -Wall -Wextra -Werror -O2 -o $@  o/AEntity.cpp.o o/colors.cpp.o o/EnnemiEntity.cpp.o o/EntityArray.cpp.o o/Game.cpp.o o/HitBox.cpp.o o/main.cpp.o o/PlayerEntity.cpp.o o/Projectile.cpp.o o/Weapon.cpp.o -lncurses && echo || printf $(MSG_1) $@

o/:
	@mkdir -p $@ 2> /dev/null || true

o/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f o/AEntity.cpp.o o/colors.cpp.o o/EnnemiEntity.cpp.o o/EntityArray.cpp.o o/Game.cpp.o o/HitBox.cpp.o o/main.cpp.o o/PlayerEntity.cpp.o o/Projectile.cpp.o o/Weapon.cpp.o 2> /dev/null || true
	@rmdir -p o 2> /dev/null || true

fclean: clean
	@rm -f ft_retro 2> /dev/null || true

re: fclean all

.PHONY: all clean fclean re make
