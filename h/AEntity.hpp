/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:22:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 16:10:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "ft_retro.hpp"
# include "Game.hpp"
# include "HitBox.hpp"

class	AEntity : public HitBox
{
public:
	enum				e_type
	{
		ENNEMI,
		PLAYER
	};

	AEntity(Game &game, Entity::e_type type, int x, int y, int w, int h);
	AEntity(AEntity const &src);
	virtual ~AEntity(void);

	e_type				getType(void) const;

	virtual void		update(void) = 0;
	virtual void		render(void) = 0;

	AEntity				&operator=(AEntity const &rhs);

protected:
	Game				&_game;

	e_type				_type;

	int					_hp;

	virtual void		_move(void) = 0;

	virtual void		_die(void);

private:
	AEntity(void);
};

#endif
