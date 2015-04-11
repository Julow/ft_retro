/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HitBox.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 18:20:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITBOX_HPP
# define HITBOX_HPP

# include "ft_retro.hpp"

class	HitBox
{
public:
	HitBox(int x, int y, int width, int height);
	virtual ~HitBox(void);

	bool				collide(HitBox const &box) const;

	int					getX(void) const;
	int					getY(void) const;
	int					getWidth(void) const;
	int					getHeight(void) const;

protected:
	int					_x;
	int					_y;
	int					_width;
	int					_height;

private:
	HitBox(void);
	HitBox(HitBox const &src);
	HitBox				&operator=(HitBox const &rhs);
};

#endif
