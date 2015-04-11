/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:02:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 17:49:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERENTITY_HPP
# define PLAYERENTITY_HPP

#include "ft_retro.hpp"
#include <iostream>
#include "AEntity.hpp"
#include "Game.hpp"

class	PlayerEntity : AEntity
{
public:
	PlayerEntity(int x, int y);
	PlayerEntity(PlayerEntity const &src);
	virtual ~PlayerEntity(void);
	PlayerEntity			&operator=(PlayerEntity const &rhs);

	virtual void		update(float t);
	virtual void		render(void);

protected:
	Weapon				_weapon;

	virtual void		_move(void);
	virtual void		_die(void);

private:
	PlayerEntity(void);
};

#endif
