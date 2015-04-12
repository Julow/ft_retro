/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 12:25:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(Game &game, AEntity::e_type type, std::string const &pattern, int x, int y, int w, int h, int hp)
	: HitBox(x, y, w, h), _game(game), _pattern(pattern), _type(type), _hp(hp)
{
}

AEntity::~AEntity(void)
{
}

Game				&AEntity::getGame(void) const
{
	return (_game);
}

AEntity::e_type		AEntity::getType(void) const
{
	return (_type);
}

int					AEntity::getHP(void) const
{
	return (_hp);
}

void				AEntity::render(void)
{
	attron(COLOR_PAIR(3));
	wmove(stdscr, _y, _x);
	printw(_pattern.c_str());
}

std::string			AEntity::getPattern(void) const
{
	return (this->_pattern);
}

bool				AEntity::moveToDirection(int x, int y)
{
	int			nx;
	int			ny;

	// Checking if the player wont go out of the screen
	nx = this->_x + x;
	ny = this->_y + y;
	if (nx >= 0 && ny >= 0)
	{
		if (((nx + this->_width) < GAME_WIDTH) &&
			((ny + this->_height) < GAME_HEIGHT))
		{
			this->_x = nx;
			this->_y = ny;
			return (true);
		}
	}
	return (false);
}
