/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:19:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:53:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "ft_retro.hpp"
# include "Weapon.hpp"

class	Projectile : public AEntity
{
public:
	Projectile(Game &game, Entity::e_type ownType, int x, int y, int dmg);
	Projectile(Projectile const &src);
	virtual ~Projectile(void);

	e_type				getOwnerType(void) const;

	int					getDmg(void) const;

	virtual void		update(float t);
	virtual void		render(void);

	Projectile			&operator=(Projectile const &rhs);

protected:
	e_type				_ownType;

	int					_dmg;

private:
	Projectile(void);
};

#endif
