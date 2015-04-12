/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:10:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 17:49:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include "Game.hpp"

int				main(void)
{
	Game			game;

	initscr();
	initColors();
	noecho();
	timeout(0);
	curs_set(0);
	keypad(stdscr, TRUE);
	game.start();
	endwin();
	return (0);
}
