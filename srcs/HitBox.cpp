/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HitBox.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:11:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 16:12:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HitBox.hpp"

HitBox::HitBox(int x, int y, int width, int height)
	: _x(x), _y(y), _width(width), _height(height)
{
}

HitBox::HitBox(HitBox const &src)
{
	*this = src;
}

HitBox::~HitBox(void)
{
}

HitBox			&HitBox:operator=(HitBox const &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	_width = rhs._width;
	_height = rhs._height;
	return (*this);
}
