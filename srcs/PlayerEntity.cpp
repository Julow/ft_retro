/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olysogub <olysogub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:36:40 by olysogub          #+#    #+#             */
/*   Updated: 2015/04/12 12:18:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(Game &game, int x, int y)
	: AEntity(game, PLAYER, "  |\n--O--\n ___", x, y, 5, 3, 100)
{
	_weapon = new Weapon(5, 1);
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
