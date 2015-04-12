/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 16:43:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMIENTITY_HPP
# define ENNEMIENTITY_HPP

# include "ft_retro.hpp"
# include "AEntity.hpp"
# include "Weapon.hpp"
# include "Game.hpp"
# include <string>

# define FLY_WIDTH		1
# define FLY_HEIGHT		1
# define SHIT_WIDTH		2
# define SHIT_HEIGHT	2

class	EnnemiEntity : public AEntity
{
public:
	struct	s_ennemi
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
