/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 18:50:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 20:15:44 by jaguillo         ###   ########.fr       */
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
	int				toSpawn;

	_level++;
	toSpawn = _level * 2 + _level;
	while (toSpawn-- > 0)
	{
		EnnemiEntity::spawn(_game, EnnemiEntity::monsters[rand() % 4].name,
			rand() % (GAME_WIDTH - 8) + 4, -(rand() % SPAWN_HEIGHT));
	}
	if ((_level % 5) == 0)
		EnnemiEntity::spawn(_game, "BOSS", rand() % (GAME_WIDTH - 10) + 5, 0);
}
