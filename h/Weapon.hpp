/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:25:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:48:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "ft_retro.hpp"
# include "Projectile.hpp"

class	Weapon
{
public:
	Weapon(Game &game, int dmg);
	Weapon(Weapon const &src);
	virtual ~Weapon(void);

	int				getDmg(void) const;

	Projectile		*createProjectile(AEntity &owner);

	Weapon			&operator=(Weapon const &rhs);

protected:
	Game			&_game;

	int				_dmg;

private:
	Weapon(void);
};

#endif
