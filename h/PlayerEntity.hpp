/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:02:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 14:33:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERENTITY_HPP
# define PLAYERENTITY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include "Weapon.hpp"
# include <iostream>

# define PLAYER_WIDTH	5
# define PLAYER_HEIGHT	2
# define PLAYER_HP		100

class	PlayerEntity : public AEntity
{
public:
	PlayerEntity(Game &game, int x, int y);
	virtual ~PlayerEntity(void);

	Weapon					&getWeapon(void) const;

	virtual void			update(float t);
	virtual void			render(void);

protected:
	Weapon					*_weapon;

private:
	PlayerEntity(void);
	PlayerEntity(PlayerEntity const &src);
	PlayerEntity			&operator=(PlayerEntity const &rhs);
};

#endif
