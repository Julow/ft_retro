/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 15:59:58 by jaguillo         ###   ########.fr       */
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
	virtual ~Game(void);

	void			start(void);

protected:
	EntityArray		_ents;
	EntityArray		_projectiles;

	PlayerEntity	_player;

	void			_update(void);

	void			_render(void);

private:
	Game(Game const &src);

	Game			&operator=(Game const &rhs);
};

#endif
