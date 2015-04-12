/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:22:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 12:17:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "ft_retro.hpp"
# include "HitBox.hpp"
# include <string>

class	AEntity : public HitBox
{
public:
	enum				e_type
	{
		ENNEMI,
		PROJECTILE,
		PLAYER
	};

	AEntity(Game &game, AEntity::e_type type, std::string const &pattern, int x, int y, int w, int h, int hp);
	virtual ~AEntity(void);

	Game				&getGame(void) const;
	e_type				getType(void) const;
	int					getHP(void) const;

	virtual void		update(float t) = 0;
	virtual void		render(void);
	virtual bool		moveToDirection(int x, int y);

protected:
	Game				&_game;

	std::string			_pattern;

	e_type				_type;

	int					_hp;

private:
	AEntity(void);
	AEntity(AEntity const &src);
	AEntity				&operator=(AEntity const &rhs);
};

#endif
