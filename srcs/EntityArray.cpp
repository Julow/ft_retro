/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityArray.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:16:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 15:47:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityArray.hpp"

EntityArray::EntityArray(void)
	: _ents(NULL)
{
}

EntityArray::EntityArray(EntityArray const &src)
	: _ents(NULL)
{
	*this = src;
}

EntityArray::~EntityArray(void)
{
	if (_ents != NULL)
		delete [] _ents;
}

AEntity				*EntityArray::get(int i) const
{
	if (i < 0 || i >= _count)
		return (NULL);
	return (_ents[i]);
}

int					EntityArray::count(void) const
{
	return (_count);
}

void				EntityArray::add(AEntity *ent)
{
	AEntity				**tmp;
	int					i;

	tmp = new AEntity*[_count + 1];
	for (i = 0; i < _count; i++)
		tmp[i] = _ents[i];
	tmp[i] = ent;
	delete [] _ents;
	_ents = tmp;
}

AEntity				*EntityArray::rem(int i)
{
	AEntity				*tmp;

	if (i < 0 || i >= _count)
		return (NULL);
	tmp = _ents[i];
	for (i++; i < _count; i++)
		_ents[i - 1] = _ents[i];
	_count--;
	return (tmp);
}

void				EntityArray::updateAll(void) const
{
	int					i;

	for (i = 0; i < _count; i++)
	{
		if (_ents[i] != NULL)
			_ents[i].update();
	}
}

EntityArray			&EntityArray::operator=(EntityArray const &rhs)
{
	int					i;

	if (_ents != NULL)
		delete [] _ents;
	_ents = new AEntity*[rhs._count];
	_count = rhs._count;
	for (i = 0; i < _count; i++)
		_ents[i] = rhs._ents[i];
	return (*this);
}
