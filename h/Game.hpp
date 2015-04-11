/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 13:57:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"

class	Game
{
public:
	Game(void);
	Game(Game const &src);
	virtual ~Game(void);

	void			start(void);

	Game			&operator=(Game const &rhs);

protected:
	EntityArray		_ents;
	EntityArray		_projectiles;

	PlayerEntity	_player;

	void			_updateEntity(void);
	void			_updateGame(void);

	void			_render(void);

private:
};

#endif
