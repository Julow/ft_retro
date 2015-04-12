/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:19:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 17:00:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(Game &game, AEntity::e_type ownType, int x, int y, int dmg)
	: AEntity(game, PROJECTILE, "o", x, y, 1, 1, 1), _ownType(ownType), _dmg(dmg), _rest(0)
{
}

Projectile::~Projectile(void)
{
}

AEntity::e_type		Projectile::getOwnerType(void) const
{
	return (_ownType);
}

void				Projectile::update(float t)
{
	_rest += t * 40;
	while (_rest >= 1)
	{
		moveToDirection(0, ((_ownType == AEntity::PLAYER) ? -1 : 1));
		_rest--;
	}
	if (_y < 0 || _y >= GAME_HEIGHT)
	{
		_hp = 0;
		return ;
	}
}

void				Projectile::render(void)
{
	_game.wmove(_x, _y);
	printw("|");
}

int					Projectile::getDmg(void) const
{
	return (_dmg);
}
