/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:52:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
	: _ents(), _projectiles(), _player(*this, 0, 0), _score(0)
{
	this->_tbegin = std::time(0);
	_updateOffset();
}

Game::~Game(void)
{
}

void				Game::start(void)
{
	clock_t				last_update;
	float				t;


	last_update = clock();
	while (true)
	{
		_handleKey(getch());
		t = (clock() - last_update) / CLOCKS_PER_SEC;
		_update(t);
		_render();
	}
}

EntityArray			&Game::getEntities(void)
{
	return (_ents);
}

EntityArray			&Game::getProjectiles(void)
{
	return (_projectiles);
}

PlayerEntity		&Game::getPlayer(void)
{
	return (_player);
}

t_pt				Game::getOffset(void) const
{
	return (_offset);
}

void				Game::_updateOffset(void)
{
	t_pt				pt;

	getmaxyx(stdscr, pt.x, pt.y);
	if (pt.x == _offset.x || pt.y == _offset.y)
		return ;
	_offset.x = (GAME_WIDTH - pt.x) / 2;
	_offset.y = (GAME_HEIGHT - pt.y) / 2;
	_offset.x = 10;
	_offset.y = 10;
}

void				Game::_handleKey(int key)
{
	if (key == KEY_UP)
		_player.moveToDirection(1, 0);
	else if (key == KEY_RIGHT)
		_player.moveToDirection(0, 1);
	else if (key == KEY_DOWN)
		_player.moveToDirection(-1, 0);
	else if (key == KEY_LEFT)
		_player.moveToDirection(0, -1);
	else
		_updateOffset();
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
	_printBorder(); // Prints the game border
	_printGameInfo();
	_ents.renderAll();
	_player.render();
	_projectiles.renderAll();
	refresh();
}


void				Game::_printBorder(void)
{
	int					x;
	int					y;

	attron(COLOR_PAIR(3));

	y = _offset.y - 1;
	x = _offset.x - 1;
	while (y < (GAME_HEIGHT + _offset.y))
	{
		x = _offset.x - 1;
		while (x < (GAME_WIDTH + _offset.x))
		{
			if (y == (_offset.y - 1) || (y == (_offset.y + GAME_HEIGHT - 1)))
			{
				wmove(stdscr, y, x);
				printw(" ");
			}
			else if (x == (_offset.x - 1) || (x == (_offset.x + GAME_WIDTH - 1)))
			{
				wmove(stdscr, y, x);
				printw(" ");
			}
			x++;
		}
		y++;
	}
}

void				Game::_printGameInfo(void)
{
	int				i;

	attron(COLOR_PAIR(4));
	move(_offset.y - 4, _offset.x);
	printw("Score: ");
	attron(COLOR_PAIR(1));
	printw("%d", this->_score);
	attron(COLOR_PAIR(4));
	printw("\t\t Time: ");
	attron(COLOR_PAIR(1));
	printw(" %d", (time(NULL) - _tbegin));
	attron(COLOR_PAIR(4));
	printw("\t\t\tLifes: ");
	attron(COLOR_PAIR(2));
	i = 0;
	// /!\ Replace 3 with the number of hp
	while (i < 3)
	{
		printw("<3 ");
		i++;
	}
	attron(COLOR_PAIR(0));
}


