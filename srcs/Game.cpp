/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:09:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
	: _ents(), _projectiles(), _player(0, 0)
{
}

Game::~Game(void)
{
}

void				Game::start(void)
{
	clock_t				last_update;
	float				t;
	int					key;

	last_update = clock();
	while (true)
	{
		_handleKey(getch());
		t = (clock() - last_update) / CLOCKS_PER_SEC;
		_update(t);
		_render();
	}
}

void				Game::_handleKey(int key)
{
	if (key == KEY_UP)
		_player.move(1, 0);
	else if (key == KEY_RIGHT)
		_player.move(0, 1);
	else if (key == KEY_DOWN)
		_player.move(-1, 0);
	else if (key == KEY_LEFT)
		_player.move(0, -1);
}

void				Game::_update(float t)
{
	_ents.updateAll(t);
	_player.update(t);
	_projectiles.updateAll(t);
}

void				Game::_render(void)
{
	clear();
	_ents.renderAll();
	_player.render();
	_projectiles.renderAll();
	refresh();
}
