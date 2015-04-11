/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:10:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:04:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

int				main(void)
{
	Game			game;

	initscr();
	noecho();
	timeout(30);
	keypad(stdscr, TRUE);
	game.start();
	endwin();
	return (0);
}
