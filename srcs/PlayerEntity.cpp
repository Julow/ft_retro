/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/11 17:06:22 by olysogub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(void)
{
}

PlayerEntity::~PlayerEntity(void)
{
}

PlayerEntity::PlayerEntity(PlayerEntity const &src)
{
	*this = src;
}

PlayerEntity &				operator=(PlayerEntity const &rhs)
{
	AEntity::operator=(ths);
	return (*this);
}

void						PlayerEntity::update(float t)
{
	// Will handle the keys of the player
}

void						PlayerEntity::render(void)
{

}

void						PlayerEntity::_move()
{
	return ;
}

void						PlayerEntity::_die(void)
{
	return ;
}
