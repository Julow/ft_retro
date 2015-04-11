/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:38:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 15:44:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYARRAY_HPP
# define ENTITYARRAY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"

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

	void				updateAll(void) const;

	EntityArray			&operator=(EntityArray const &rhs);

protected:
	AEntity				**_ents;

	int					_count;

private:
};

#endif
