/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/12 12:18:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"
#include "Game.hpp"

PlayerEntity::PlayerEntity(Game &game, int x, int y)
	: AEntity(game, PLAYER, "==^==\n-|-|-", x, y, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_HP)
{
	_weapon = new Weapon(5, 1);
}

PlayerEntity::~PlayerEntity(void)
{
	delete _weapon;
}

void						PlayerEntity::update(float t)
{
	(void)t;
}

void						PlayerEntity::render(void)
{
	int					i;
	int					bing;
	char	 const		*str;

	// /!\ Remplacer les 10 par les offsets
	bing = 0;
	wmove(stdscr, this->_y + _game.getOffset().y , this->_x + _game.getOffset().x);
	i = 0;
	str = this->_pattern.c_str();
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			bing++;
			wmove(stdscr, this->_y + bing + _game.getOffset().y, this->_x + _game.getOffset().x);
		}
		else
			addch(str[i]);
		i++;
	}
}
