/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 18:50:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:40:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
# define LEVEL_HPP

# include "ft_retro.hpp"

# define SPAWN_HEIGHT	30

class	Level
{
public:
	Level(Game &game);
	virtual ~Level(void);

	int				getLevel(void) const;

	void			update();

protected:
	Game			&_game;

	int				_level;

	void			_newLevel(void);

private:
	Level(void);
	Level(Level const &src);

	Level			&operator=(Level const &rhs);
};

#endif
