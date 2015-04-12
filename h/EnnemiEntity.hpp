/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 19:20:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMIENTITY_HPP
# define ENNEMIENTITY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include "Weapon.hpp"
# include "Game.hpp"
# include <string>

class	EnnemiEntity : public AEntity
{
public:
	struct	s_bad
	{
		std::string		name;
		std::string		pattern;
		int				width;
		int				height;
		int				hp;
		int				speed;
		Weapon			*weapon;
	};

	EnnemiEntity(Game &g, std::string const &p, int x, int y, int width, int h, int s, int hp, Weapon *w);
	virtual ~EnnemiEntity(void);

	virtual void		update(float t);

	static void			spawn(Game &game, std::string const &type, int x, int y);

	static s_bad		monsters[];

protected:
	Weapon				*_weapon;
	std::string			_pattern;

	float					_rest;
	float				_moveSpeed;

private:
	EnnemiEntity(void);
	EnnemiEntity(EnnemiEntity const &src);
	EnnemiEntity		&operator=(EnnemiEntity const &rhs);
};

#endif
