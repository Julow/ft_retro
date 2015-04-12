/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityArray.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:16:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 15:51:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityArray.hpp"
#include "Game.hpp"

EntityArray::EntityArray(void)
	: _ents(NULL), _count(0), _alloc(0)
{
}

EntityArray::EntityArray(EntityArray const &src)
	: _ents(NULL), _count(0), _alloc(0)
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
	_extend();
	_ents[_count] = ent;
	_count++;
}

AEntity				*EntityArray::rem(int i)
{
	AEntity				*tmp;

	if (i < 0 || i >= _count)
	tmp = _ents[i];
	for (i++; i < _count; i++)
		_ents[i - 1] = _ents[i];
	_count--;
	return (tmp);
}

AEntity				*EntityArray::collideAll(AEntity &ent, AEntity::e_type ownType)
{
	int					i;

	for (i = 0; i < _count; i++)
	{
		if (_ents[i]->getType() != ownType && ent.collide(*_ents[i]))
			return (_ents[i]);
	}
	return (NULL);
}

void				EntityArray::updateAll(float t)
{
	int					i;
	Projectile			*tmp;

	for (i = 0; i < _count; i++)
	{
		if (_ents[i] != NULL)
		{
			tmp = (Projectile*)(&_ents[i]->getGame())->getProjectiles().collideAll(*_ents[i], _ents[i]->getType());
			if (tmp != NULL)
				_ents[i]->damage(tmp->getDmg());
			_ents[i]->update(t);
			if (_ents[i]->getHP() <= 0)
			{
				rem(i);
				i--;
			}
		}
	}
}

void				EntityArray::renderAll(void) const
{
	int					i;

	for (i = 0; i < _count; i++)
	{
		if (_ents[i] != NULL)
			_ents[i]->render();
	}
}

void				EntityArray::_extend(void)
{
	AEntity				**tmp;
	int					len;

	len = _alloc;
	while (_count >= len)
		len += EXTEND_CHUNK;
	if (_alloc == len)
		return ;
	tmp = new AEntity*[len];
	_alloc = len;
	for (len = 0; len < _count; len++)
		tmp[len] = _ents[len];
	delete [] _ents;
	_ents = tmp;
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
