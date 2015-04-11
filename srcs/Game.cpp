/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:59:15 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
	: _ents(), _projectiles(), _player(0, 0), _score(0)
{
	this->_tbegin = std::time(0);
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

EntityArray			&Game::getEntities(void)
{
	return (_ents)
}

EntityArray			&Game::getProjectiles(void)
{
	return (_projectiles)
}

PlayerEntity		&Game::getPlayer(void)
{
	return (_player)
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
	_ents.renderAll();
	_player.render();
	_projectiles.renderAll();
	refresh();
}


void				Game::_printBorder(void)
{
	int					x;
	int					y;

	attron(COLOR_PAIR(1));
	y = this->_offset().y - 1;
	x = this->_offset().x - 1;
	while (y < GAME_HEIGHT)
	{
		while (x < GAME_WIDTH)
		{
			if (y == (this->_offset().y - 1) || (y == (this->_offset().y + GAME_HEIGHT - 2)))
				printw("=");
			else if (x == (this->_offset().x - 1) || (x == (this->_offset().x + GAME_WIDTH - 2)))
				printw("|");
			else
				printw(" ");
			x++;
		}
		printw("\n");
		y++;
	}
}

void				Game::_printGameInfo(void)
{
	std:ostringstream		oss;

	attron(COLOR_PAIR(2));
	move(_offset().y - 6, _offset().x);
	printw("Score: ");
	oss << this->_score;
	printw(oss.str().c_str());
	printw("\t\t");
	printw("Time: ");
	oss.str("");
	oss.clear();
	oss << _getGameTime() << " sec";
	printw(oss.str().c_str());
	printw("\t\t");
	printw("Lifes: ");
	printw("<3 <3 <3");
	return ;
}


double				Game::_getGameTime(void)
{
	return (difftime(time(0), this->_tbegin);
}
