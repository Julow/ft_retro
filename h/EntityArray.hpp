/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:38:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 15:47:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYARRAY_HPP
# define ENTITYARRAY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"

# define EXTEND_CHUNK	32

class	EntityArray
{
public:
	EntityArray(void);
	EntityArray(EntityArray const &src);
	virtual ~EntityArray(void);

	AEntity				*get(int i) const;
	void				add(AEntity *ent);
	AEntity				*rem(int i);

	int					count(void) const;

	AEntity				*collideAll(AEntity &ent, AEntity::e_type ownType);

	void				updateAll(float t);
	void				renderAll(void) const;

	EntityArray			&operator=(EntityArray const &rhs);

protected:
	AEntity				**_ents;

	int					_count;
	int					_alloc;

	void				_extend(void);

private:
};

#endif
