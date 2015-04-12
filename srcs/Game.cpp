/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:29 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 17:05:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <chrono>

Game::Game(void)
	: _ents(), _projectiles(), _spawnTimeout(5), _score(0), _level(0)
{
	_tbegin = std::time(0);
	_player = new PlayerEntity(*this, (GAME_WIDTH / 2) - (int)(PLAYER_WIDTH / 2), (GAME_HEIGHT - 1 - PLAYER_HEIGHT));
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
		t = (float)(clock() - last_update) / CLOCKS_PER_SEC;
		_update(t);
		if (this->isGameover())
			break ;
		else
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
	return (*_player);
}

t_pt				Game::getOffset(void) const
{
	return (_offset);
}

void				Game::wmove(int x, int y) const
{
	::wmove(stdscr, y + _offset.y, x + _offset.x);
}

void				Game::_updateOffset(void)
{
	t_pt				pt;

	getmaxyx(stdscr, pt.x, pt.y);
	if (pt.x == _offset.x || pt.y == _offset.y)
		return ;
	_offset.x = (pt.x - GAME_WIDTH) / 2;
	_offset.y = (pt.y - GAME_HEIGHT) / 2;
	_offset.x = 10;
	_offset.y = 10;
}

void				Game::_handleKey(int key)
{
	if (key == KEY_DOWN)
		_player->moveToDirection(0, 1);
	else if (key == KEY_UP)
		_player->moveToDirection(0, -1);
	else if (key == KEY_RIGHT)
		_player->moveToDirection(1, 0);
	else if (key == KEY_LEFT)
		_player->moveToDirection(-1, 0);
	else if (key == ' ')
		_player->getWeapon().canShoot(0, *_player);
	else
		_updateOffset();
}

void				Game::_update(float t)
{
	/*
	 * Generating the ennemies waves
	 */
	if (this->getEntities().count() <= 0)
	{
		int				ennemies;
		int				i;
		int				j;
		int				cols;
		int				rows;

		this->_level += 1;
		ennemies = this->_level * 5;
		cols = (int)(GAME_WIDTH / (SHIT_WIDTH + EPADDING));
		rows = (int)(ennemies / cols);
		rows = (rows <= 0) ? 1 : rows;

		i = 0;
		while (i < rows)
		{
			j = 0;
			while (j < cols)
			{
				EnnemiEntity::spawn(*this, "Shit", j * (SHIT_WIDTH + EPADDING), i * (SHIT_HEIGHT + 1) );
				j++;
			}
			i++;
		}
	}

	/*
	 * Updating...
	 */
	// AEntity				*ent;

	// ent = _ents.collideAll(*_player, _player->getType());
	// if (ent != NULL)
		// _player->damage(_player->getHP());
	// ent = _projectiles.collideAll(*_player, _player->getType());
	// if (ent != NULL)
		// _player->damage(((Projectile*)ent)->getDmg());
	_ents.updateAll(t);
	_player->update(t);
	_projectiles.updateAll(t);
}

void				Game::_render(void)
{
	erase();
	_printBorder();
	_printGameInfo();
	_ents.renderAll();
	_player->render();
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
				::wmove(stdscr, y, x);
				printw(" ");
			}
			else if (x == (_offset.x - 1) || (x == (_offset.x + GAME_WIDTH - 1)))
			{
				::wmove(stdscr, y, x);
				printw(" ");
			}
			x++;
		}
		y++;
	}
}

bool				Game::isGameover()
{
	const char *over = "_____                                             \n\
	  / ____|                                            \n\
	 | |  __  __ _ _ __ ___   ___    _____   _____ _ __  \n\
	 | | |_ |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__| \n\
	 | |__| | (_| | | | | | |  __/ | (_) \\ V /  __/ |    \n\
	  \\_____|\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|    ";

	
	if (this->_player->getHP() <= 0)
	{
		erase();
		attron(COLOR_PAIR(2));
		this->wmove(this->_offset.x, this->_offset.y);
		printw(over);
		refresh();
		timeout(-1);
		getch();
		return (true);
	}
	return (false);
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
	printw("\t\tLevel: ");
	attron(COLOR_PAIR(1));
	printw("%d", this->_level);
	attron(COLOR_PAIR(4));
	printw("\t\t Time: ");
	attron(COLOR_PAIR(1));
	printw(" %d", (time(NULL) - _tbegin));
	attron(COLOR_PAIR(4));
	printw("\t\t\tLifes: ");
	attron(COLOR_PAIR(2));
	i = this->_player->getHP() / 20;
	while (i-- > 0)
		printw("<3 ");
	attron(COLOR_PAIR(0));
}


