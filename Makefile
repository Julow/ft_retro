# LOL

NAME := ft_retro
C_DIR := srcs
H_DIRS := h
O_DIR := o
LIBS := 
CC := clang++
FLAGS := -Wall -Wextra -Werror -O2
LINKS := -lncurses
HEADS := -Ih 

all: $(NAME)

o/AEntity.cpp.o: srcs/AEntity.cpp h/AEntity.hpp
	@$(COMPILE)
o/colors.cpp.o: srcs/colors.cpp h/ft_retro.hpp
	@$(COMPILE)
o/EnnemiEntity.cpp.o: srcs/EnnemiEntity.cpp h/EnnemiEntity.hpp
	@$(COMPILE)
o/EntityArray.cpp.o: srcs/EntityArray.cpp h/EntityArray.hpp
	@$(COMPILE)
o/Game.cpp.o: srcs/Game.cpp h/Game.hpp
	@$(COMPILE)
o/HitBox.cpp.o: srcs/HitBox.cpp h/HitBox.hpp
	@$(COMPILE)
o/main.cpp.o: srcs/main.cpp h/ft_retro.hpp h/Game.hpp
	@$(COMPILE)
o/PlayerEntity.cpp.o: srcs/PlayerEntity.cpp h/PlayerEntity.hpp h/Game.hpp
	@$(COMPILE)
o/Projectile.cpp.o: srcs/Projectile.cpp h/Projectile.hpp
	@$(COMPILE)
o/Weapon.cpp.o: srcs/Weapon.cpp h/Weapon.hpp h/Game.hpp
	@$(COMPILE)

MSG_0 := printf '\033[0;32m%-21.21s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-21.21s\033[0;0m\n'

COMPILE = $(MSG_0) $< ; $(CC) $(FLAGS) $(HEADS) -c -o $@ $< || $(MSG_1) $<

O_FILES := o/AEntity.cpp.o \
		o/colors.cpp.o \
		o/EnnemiEntity.cpp.o \
		o/EntityArray.cpp.o \
		o/Game.cpp.o \
		o/HitBox.cpp.o \
		o/main.cpp.o \
		o/PlayerEntity.cpp.o \
		o/Projectile.cpp.o \
		o/Weapon.cpp.o

$(NAME): o/ $(LIBS) $(O_FILES)
	@$(MSG_0) $@ ; $(CC) $(FLAGS) -o $@ $(O_FILES) $(LINKS) && echo || $(MSG_1) $@

o/:
	@mkdir -p $@ 2> /dev/null || true

o/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o 2> /dev/null || true

fclean: clean
	@rm -f ft_retro 2> /dev/null || true

re: fclean all

make:
	@bash 'makemake.sh' re

.PHONY: all clean fclean re make
