/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HitBox.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:11:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 15:57:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HitBox.hpp"

HitBox::HitBox(int x, int y, int width, int height)
	: _x(x), _y(y), _width(width), _height(height)
{
}

HitBox::~HitBox(void)
{
}

int				HitBox::getX(void) const
{
	return (_x);
}

int				HitBox::getY(void) const
{
	return (_y);
}

int				HitBox::getWidth(void) const
{
	return (_width);
}

int				HitBox::getHeight(void) const
{
	return (_height);
}

bool			HitBox::collide(HitBox const &box) const
{
	if (_x <= (box._x + box._width)
		&& box._x <= (_x + _width)
		&& _y <= (box._y + box._height)
		&& box._y <= (_y + _height))
		return (true);
	return (false);
}
