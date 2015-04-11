/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:05:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 16:11:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(Game &game, Entity::e_type type, int x, int y, int w, int h)
	: HitBox(x, y, w, h), _game(game), _type(type)
{
}

AEntity::AEntity(AEntity const &src)
	: _game(src._game)
{
	*this = src;
}

AEntity::~AEntity(void)
{
}

AEntity::e_type		getType(void) const
{
	return (_type);
}

AEntity				&AEntity:operator=(AEntity const &rhs)
{
	_type = rhs._type;
	_hp = rhs._hp;
	HitBox::operator=(rhs);
	return (*this);
}
