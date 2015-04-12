/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnnemiEntity.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 11:39:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/12 12:24:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMIENTITY_HPP
# define ENNEMIENTITY_HPP

# include "ft_retro.hpp"
# include <string>

class	EnnemiEntity
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
		Weapon			weapon;
	};

	EnnemiEntity(Game &g, std::string const &p, int x, int y, int w, int h, int s, int hp, Weapon &w);
	virtual ~EnnemiEntity(void);

	virtual void		update(float t);
	virtual void		render(void);

	static void			spawn(std::string const &type);

protected:
	std::string			_pattern;

	float				_moveSpeed;

private:
	EnnemiEntity(void);
	EnnemiEntity(EnnemiEntity const &src);
	EnnemiEntity		&operator=(EnnemiEntity const &rhs);
};

#endif
