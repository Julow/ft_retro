/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:44:40 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include <time.h>
# include <sstream>

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

private:
	Game(Game const &src);

	Game			&operator=(Game const &rhs);
};

#endif
