/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 14:44:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.hpp"
# include "PlayerEntity.hpp"
# include "EntityArray.hpp"
# include "EnnemiEntity.hpp"
# include <sstream>
# include <ctime>

class	Game
{
public:
	Game(void);
	virtual ~Game(void);

	void			start(void);

	EntityArray		&getEntities(void);
	EntityArray		&getProjectiles(void);
	PlayerEntity	&getPlayer(void);

	t_pt			getOffset(void) const;
	void			wmove(int x, int y) const;

protected:
	EntityArray		_ents;
	EntityArray		_projectiles;

	PlayerEntity	*_player;

	t_pt			_offset;

	float			_spawnTimeout;

	void			_updateOffset(void);
	void			_handleKey(int key);
	void			_update(float t);
	void			_render(void);
	void			_printBorder(void);
	void			_printGameInfo(void);
	int				_score;
	time_t			_tbegin;

	double			_getGameTime(void);

private:
	Game(Game const &src);
	Game			&operator=(Game const &rhs);
};

#endif
