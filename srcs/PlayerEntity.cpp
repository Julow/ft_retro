/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/11 17:50:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(Game &game, int x, int y)
	: AEntity(game, PLAYER, x, y, 1, 1), _weapon(game, 5)
{
}

PlayerEntity::~PlayerEntity(void)
{
}

PlayerEntity::PlayerEntity(PlayerEntity const &src)
{
	*this = src;
}

PlayerEntity				&operator=(PlayerEntity const &rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}

void						PlayerEntity::update(float t)
{
}

void						PlayerEntity::render(void)
{
}

void						PlayerEntity::_move(void)
{
}

void						PlayerEntity::_die(void)
{
}
