/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:39:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"
#include "Game.hpp"

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

void				AEntity::damage(int dmg)
{
	_hp -= dmg;
}

void				AEntity::render(void)
{
	int					i;
	int					bing;
	char const			*str;

	if (_y < 0)
		return ;
	attron(COLOR_PAIR(5));
	bing = 0;
	_game.wmove(_x, _y);
	i = 0;
	str = this->_pattern.c_str();
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			bing++;
			_game.wmove(_x, _y + bing);
		}
		else
			addch(str[i]);
		i++;
	}	
}

std::string			AEntity::getPattern(void) const
{
	return (this->_pattern);
}

bool				AEntity::moveToDirection(int x, int y)
{
	_x += x;
	_y += y;
	return (true);
}
