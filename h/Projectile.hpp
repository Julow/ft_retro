/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:19:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 15:03:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include "Game.hpp"
# include <cmath>

class	Projectile : public AEntity
{
public:
	Projectile(Game &game, AEntity::e_type ownType, int x, int y, int dmg);
	virtual ~Projectile(void);

	AEntity::e_type		getOwnerType(void) const;

	int					getDmg(void) const;

	virtual void		update(float t);
	virtual void		render(void);

protected:
	AEntity::e_type		_ownType;

	int					_dmg;
	float				_rest;

private:
	Projectile(void);
	Projectile(Projectile const &src);
	Projectile			&operator=(Projectile const &rhs);
};

#endif
