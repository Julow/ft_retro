/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 12:24:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "ft_retro.hpp"
# include "Projectile.hpp"
# include "AEntity.hpp"

class	Weapon
{
public:
	Weapon(int dmg, int interval);
	virtual ~Weapon(void);

	int				getDmg(void) const;
	bool			canShoot(float t, AEntity &owner);

	Projectile		*createProjectile(AEntity &owner);

protected:
	int				_dmg;
	int				_shootInterval;
	float			_shootTimeout;

private:
	Weapon(void);
	Weapon(Weapon const &src);
	Weapon			&operator=(Weapon const &rhs);
};

#endif
