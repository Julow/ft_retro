/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:02:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 14:02:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERENTITY_HPP
# define PLAYERENTITY_HPP

class	PlayerEntity
{
public:
	PlayerEntity(Game &game);
	PlayerEntity(PlayerEntity const &src);
	virtual ~PlayerEntity(void);

	PlayerEntity			&operator=(PlayerEntity const &rhs);

protected:

private:
	PlayerEntity(void);
};

#endif
