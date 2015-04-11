/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:22:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:53:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "ft_retro.hpp"
# include "HitBox.hpp"

class	AEntity : public HitBox
{
public:
	enum				e_type
	{
		ENNEMI,
		PROJECTILE,
		PLAYER
	};

	AEntity(Game &game, AEntity::e_type type, int x, int y, int w, int h);
	virtual ~AEntity(void);

	e_type				getType(void) const;

	virtual void		update(float t) = 0;
	virtual void		render(void) = 0;
	virtual bool		moveToDirection(int x, int y);

protected:
	Game				&_game;

	e_type				_type;

	int					_hp;

private:
	AEntity(void);
	AEntity(AEntity const &src);
	AEntity				&operator=(AEntity const &rhs);
};

#endif
