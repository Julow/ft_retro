/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:10:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 17:49:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include <ncurses.h>

# ifndef NULL
#  define NULL			((void*)0)
# endif

# define GAME_WIDTH		100
# define GAME_HEIGHT	50

# define EPADDING		5

# define FPS			(30 / 1000)

typedef struct	s_pt
{
	int				x;
	int				y;
}				t_pt;

class	HitBox;
class	AEntity;
class	PlayerEntity;
class	Game;
class	Weapon;
class	EntityArray;
class	Projectile;
class	EnnemiEntity;

void					initColors(void);

#endif
