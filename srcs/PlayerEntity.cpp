/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/11 18:44:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(Game &game, int x, int y)
	: AEntity(game, PLAYER, x, y, 1, 1)
{
	_weapon = new Weapon(game, 5);
}

PlayerEntity::~PlayerEntity(void)
{
	delete _weapon;
}

void						PlayerEntity::update(float t)
{
	(void)t;
}

void						PlayerEntity::render(void)
{
}
