/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:56:08 by jaguillo         ###   ########.fr       */
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
	Weapon(Game &game, int dmg);
	virtual ~Weapon(void);

	int				getDmg(void) const;

	Projectile		*createProjectile(AEntity &owner);

protected:
	Game			&_game;

	int				_dmg;

private:
	Weapon(void);
	Weapon(Weapon const &src);
	Weapon			&operator=(Weapon const &rhs);
};

#endif
