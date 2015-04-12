/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 12:23:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnnemiEntity.hpp"

const EnnemiEntity::t_ennemi	g_ennemies[] = {
	{"Fly", "*", 1, 1, 10, 10, Weapon(1, 1)},
	{"Shit", "&", 1, 1, 100, 2, Weapon(20, 5)}
}

EnnemiEntity::EnnemiEntity(Game &g, std::string const &p, int x, int y, int w, int h, int s, int hp, Weapon &w)
	: AEntity(g, ENNEMI, p, x, y, w, h, hp), _moveSpeed(s), _weapon(w)
{
}

EnnemiEntity::~EnnemiEntity(void)
{
}

void					EnnemiEntity::update(float t)
{
	moveToDirection(-(t * _moveSpeed), 0);
	_weapon.canShoot(t, *this);
}

void					EnnemiEntity::spawn(std::string const &type, int x, int y)
{
	int						i;

	for (i = 0; i < 2; i++)
	{
		if (type == g_ennemies[i])
		{
			_game.getEntities().add(new EnnemiEntity(_game, g_ennemies[i].pattern, x, y,
				g_ennemies[i].width, g_ennemies[i].height, g_ennemies[i].speed, g_ennemies[i].hp, g_ennemies[i].weapon))
			return ;
		}
	}
}
