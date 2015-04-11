/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:19:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:57:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(Game &game, AEntity::e_type ownType, int x, int y, int dmg)
	: AEntity(game, PROJECTILE, x, y, 1, 1), _ownType(ownType), _dmg(dmg)
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
	moveToDirection(0, 50 * t);
}

void				Projectile::render(void)
{
	wmove(stdscr, _x, _y);
	printw("-");
}

int					Projectile::getDmg(void) const
{
	return (_dmg);
}
