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

const EnnemiEntity::s_ennemi	g_ennemies[] = {
	{"Fly", "*", 1, 1, 10, 10, new Weapon(1, 1)},
	{"Shit", "==\n**", 2, 2, 100, 2, new Weapon(20, 5)}
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
	moveToDirection(-(t * _moveSpeed), 0);
	_weapon->canShoot(t, *this);
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

void				EnnemiEntity::render(void)
{
	int					i;
	int					bing;
	char const			*str;

	attron(COLOR_PAIR(5));
	bing = 0;
	_game.wmove(_x, _y);
	i = 0;
	str = this->_pattern.c_str();
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			bing++;
			_game.wmove(_x, _y + bing);
		}
		else
			addch(str[i]);
		i++;
	}	
}