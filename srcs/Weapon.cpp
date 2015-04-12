/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 16:56:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Game.hpp"

Weapon::Weapon(int dmg, int interval)
	: _dmg(dmg), _shootInterval(interval), _shootTimeout(interval)
{
}

Weapon::~Weapon(void)
{
}

int				Weapon::getDmg(void) const
{
	return (_dmg);
}

/*
** Check if can shoot and shoot
*/
bool			Weapon::canShoot(float t, AEntity &owner)
{
	_shootTimeout -= t;
	if (_shootTimeout <= 0)
	{
		_shootTimeout = _shootInterval;
		createProjectile(owner);
		return (true);
	}
	return (false);
}

Projectile		*Weapon::createProjectile(AEntity &owner)
{
	Projectile		*project;

	project = new Projectile(owner.getGame(), owner.getType(), owner.getX() + (owner.getWidth() / 2), owner.getY(), _dmg);
	owner.getGame().getProjectiles().add(project);
	return (project);
}
