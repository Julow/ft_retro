/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:52:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(Game &game, int dmg)
	: _game(game), _dmg(dmg)
{
}

Weapon::Weapon(Weapon const &src)
{
	*this = src;
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

	project = new Projectile(game, owner.getType(), owner.getX(), owner.getY(), _dmg);
	_game.getProjectiles.add(project);
	return (project);
}

Weapon			&Weapon::operator=(Weapon const &rhs)
{
	_dmg = rhs._dmg;
	return (*this);
}
