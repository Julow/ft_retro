/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/12 14:46:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"
#include "Game.hpp"

PlayerEntity::PlayerEntity(Game &game, int x, int y)
	: AEntity(game, PLAYER, "==^==\n-|-|-", x, y, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_HP)
{
	_weapon = new Weapon(5, 0);
}

PlayerEntity::~PlayerEntity(void)
{
	delete _weapon;
}

Weapon						&PlayerEntity::getWeapon(void) const
{
	return (*_weapon);
}

void						PlayerEntity::update(float t)
{
	(void)t;
}

void						PlayerEntity::render(void)
{
	int					i;
	int					bing;
	char const			*str;

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
