/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 17:20:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnnemiEntity.hpp"

const EnnemiEntity::s_ennemi	g_ennemies[] = {
	{"Fly", "*", 1, 1, 10, 10, new Weapon(1, 1)},
	{"Shit", "==\n**", 2, 2, 100, 10, new Weapon(20, 5)}
};

EnnemiEntity::EnnemiEntity(Game &g, std::string const &p, int x, int y, int width, int h, int s, int hp, Weapon *w)
	: AEntity(g, ENNEMI, p, x, y, width, h, hp), _weapon(w), _pattern(p), _moveSpeed(s)
{
}

EnnemiEntity::~EnnemiEntity(void)
{
}

void					EnnemiEntity::update(float t)
{
	moveToDirection(0, (t * _moveSpeed));
	_weapon->canShoot(t, *this);
	// moveToDirection(0, 1);
	if (_y > GAME_HEIGHT)
		_hp = 0;
}

void					EnnemiEntity::spawn(Game &game, std::string const &type, int x, int y)
{
	int						i;

	for (i = 0; i < 2; i++)
	{
		if (type.compare(g_ennemies[i].name) == 0)
		{
			game.getEntities().add(new EnnemiEntity(game, g_ennemies[i].pattern, x, y,
				g_ennemies[i].width, g_ennemies[i].height, g_ennemies[i].speed, g_ennemies[i].hp, g_ennemies[i].weapon));
			return ;
		}
	}
}
