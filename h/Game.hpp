/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:10:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_retro.hpp"
# include "PlayerEntity.hpp"
# include "EntityArray.hpp"
# include "EnnemiEntity.hpp"
# include "Level.hpp"
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
	int				getLevel(void) const;

	void			addScore(int s);

	t_pt			getOffset(void) const;
	void			wmove(int x, int y) const;

protected:
	EntityArray		_ents;
	EntityArray		_projectiles;
	PlayerEntity	*_player;

	t_pt			_offset;

	Level			_level;

	int				_score;
	time_t			_tbegin;

	void			_update(float t);
	void			_updateOffset(void);
	void			_handleKey(int key);
	bool			isGameover();

	void			_render(void);
	void			_printBorder(void);
	void			_printGameInfo(void);
	double			_getGameTime(void);

private:
	Game(Game const &src);
	Game			&operator=(Game const &rhs);
};

#endif
