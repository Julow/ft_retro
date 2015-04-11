/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:57:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Game.hpp"

Weapon::Weapon(Game &game, int dmg)
	: _game(game), _dmg(dmg)
{
}

Weapon::~Weapon(void)
{
}

int				Weapon::getDmg(void) const
{
	return (_dmg);
}

Projectile		*Weapon::createProjectile(AEntity &owner)
{
	Projectile		*project;

	project = new Projectile(_game, owner.getType(), owner.getX(), owner.getY(), _dmg);
	_game.getProjectiles().add(project);
	return (project);
}
