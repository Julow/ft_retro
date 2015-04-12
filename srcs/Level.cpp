/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 18:50:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:48:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Level.hpp"
#include "Game.hpp"
#include <cstdlib>

Level::Level(Game &game)
	: _game(game), _level(0)
{
}

Level::~Level(void)
{
}

int				Level::getLevel(void) const
{
	return (_level);
}

void			Level::update()
{
	if (_game.getEntities().count() <= 0)
		_newLevel();
}

void			Level::_newLevel(void)
{
	int				len;
	int				toSpawn;

	len = 0;
	for (len = 0; EnnemiEntity::monsters[len].weapon != NULL; len++)
		;
	_level++;
	toSpawn = _level * 2 + _level;
	while (toSpawn-- > 0)
	{
		EnnemiEntity::spawn(_game, EnnemiEntity::monsters[rand() % len].name,
			rand() % (GAME_WIDTH - 4) + 2, -(rand() % SPAWN_HEIGHT));
	}
}
