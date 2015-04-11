/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:22:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 14:02:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "ft_retro.hpp"
# include "HitBox.hpp"

class	AEntity : public HitBox
{
public:
	AEntity(Game &game);
	AEntity(AEntity const &src);
	virtual ~AEntity(void);

	virtual void		update(void) = 0;
	virtual void		render(void) = 0;

	AEntity				&operator=(AEntity const &rhs);

protected:
	Game				&_game;

	int					_hp;

	virtual void		_move(void) = 0;

	virtual void		_die(void);

private:
	AEntity(void);
};

#endif
