/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:46:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnnemiEntity.hpp"

EnnemiEntity::s_bad		EnnemiEntity::monsters[] = {
	{"Fly", "*", 1, 1, 1, 20, new Weapon(1, 1)},
	{"Shit", "==\n**", 2, 2, 10, 8, new Weapon(15, 2)},
	{"Snake", "(\n)\n(\n)\n0", 1, 5, 20, 3, new Weapon(35, 4)},
	{"", "", 0, 0, 0, 0, NULL}
};

EnnemiEntity::EnnemiEntity(Game &g, std::string const &p, int x, int y, int width, int h, int s, int hp, Weapon *w)
	: AEntity(g, ENNEMI, p, x, y, width, h, hp), _weapon(w), _pattern(p), _rest(0), _moveSpeed(s)
{
}

EnnemiEntity::~EnnemiEntity(void)
{
	_game.addScore(1);
}

void					EnnemiEntity::update(float t)
{
	_rest += t * _moveSpeed;
	while (_rest >= 1)
	{
		moveToDirection(0, 1);
		_rest--;
	}
	_weapon->canShoot(t, *this);
	if (_y > (GAME_HEIGHT - _height - 1))
		_hp = 0;
}

void					EnnemiEntity::spawn(Game &game, std::string const &type, int x, int y)
{
	int						i;

	for (i = 0; monsters[i].weapon != NULL; i++)
	{
		if (type.compare(monsters[i].name) == 0)
		{
			game.getEntities().add(new EnnemiEntity(game, monsters[i].pattern, x, y,
				monsters[i].width, monsters[i].height, monsters[i].speed, monsters[i].hp, monsters[i].weapon));
			return ;
		}
	}
}
