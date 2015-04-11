/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:02:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:53:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERENTITY_HPP
# define PLAYERENTITY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include "Weapon.hpp"
# include <iostream>

class	PlayerEntity : public AEntity
{
public:
	PlayerEntity(Game &game, int x, int y);
	virtual ~PlayerEntity(void);

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
