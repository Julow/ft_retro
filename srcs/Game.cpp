/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:45:48 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(void)
	: _ents(), _projectiles(), _player(0, 0), _score(0)
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
	_printBorder(); // Prints the game border
	_ents.renderAll();
	_player.render();
	_projectiles.renderAll();
	refresh();
}


void				Game::_printBorder(void)
{
	std::string			tmp("");
	int					x;
	int					y;

	attron(COLOR_PAIR(1));
	y = this->_offset().y -1;
	x = this->_offset().x -1;
	while (y < GAME_HEIGHT)
	{
		while (x < GAME_WIDTH)
		{
			if (y == (this->_offset().y - 1) || (y == (this->_offset().y + GAME_HEIGHT - 2)))
				tmp.append("=");
			else if (x == (this->_offset().x - 1) || (x == (this->_offset().x + GAME_WIDTH - 2)))
				tmp.append("|");
			else
				tmp.append(" ");
		}
		tmp.append("\n");
		printw(tmp.c_str());
		tmp.clear();
		tmp = "";
		y++;
	}
}

void				Game::_printGameInfo(void)
{
	std::string				tmp;
	std:ostringstream		oss;
	attron(COLOR_PAIR(2));
	move(_offset().y - 6, _offset().x);
	printw("Score :");
	oss << this->_score;
	printw(oss.str().c_str());
	
	return ;
}
