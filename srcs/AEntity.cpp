/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:55:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(Game &game, AEntity::e_type type, int x, int y, int w, int h)
	: HitBox(x, y, w, h), _game(game), _type(type)
{
}

AEntity::~AEntity(void)
{
}

AEntity::e_type		AEntity::getType(void) const
{
	return (_type);
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
			((nx + this->_height) < GAME_HEIGHT))
		{
			this->_x = nx;
			this->_y = ny;
			return (true);
		}
	}
	return (false);
}
