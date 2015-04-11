/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:58:26 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include <time.h>
# include <sstream>
# include <ctime>

class	Game
{
public:
	Game(void);
	virtual ~Game(void);

	void			start(void);

protected:
	EntityArray		_ents;
	EntityArray		_projectiles;

	PlayerEntity	_player;

	void			_handleKey(int key);
	void			_update(float t);
	void			_render(void);
	void			_printBorder(void);
	int				_score;
	time_t			_tbegin;

	double			_getGameTime(void);

private:
	Game(Game const &src);

	Game			&operator=(Game const &rhs);
};

#endif
